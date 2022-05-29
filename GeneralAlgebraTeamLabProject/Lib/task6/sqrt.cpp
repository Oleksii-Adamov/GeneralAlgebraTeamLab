#include "sqrt.h"

#include <set>
#include <cstdint>
#include <map>
#include <algorithm>
#include <vector>

int64_t gcd(int64_t a, int64_t b) {
  while (b) {
    auto t = b;
    b = a % b;
    a = t;
  }
  return a;
}

bool is_power_of_two(int64_t n) {
  return (n & (n - 1)) == 0;
}

int64_t mod_mul(int64_t a, int64_t b, int64_t m) {
  int64_t result = 0;
  a %= m;
  b %= m;
  while (b) {
    if (b & 1) {
      result = (result + a) % m;
    }
    a = (a + a) % m;
    b >>= 1;
  }
  return result;
}

int64_t mod_pow(int64_t a, int64_t b, int64_t m) {
  int64_t result = 1;
  a %= m;
  while (b) {
    if (b & 1) {
      result = mod_mul(result, a, m);
    }
    a = mod_mul(a, a, m);
    b >>= 1;
  }
  return result;
}

int64_t legendre_symbol(int64_t a, int64_t p) {
  return mod_pow(a, (p - 1)/2, p);
}

int64_t is_quadratic_residue(int64_t a, int64_t p) {
  return legendre_symbol(a, p) == 1;
}

std::vector<int64_t> tonelli_shanks(int64_t n, int64_t p) {
  if (!is_quadratic_residue(n, p)) return {};

  int64_t q{p - 1};
  int64_t s{0};
  while (~q & 1) {
    q >>= 1;
    s += 1;
  }

  if (s == 1) {
    const auto x{mod_pow(n, (p + 1)/4, p)};
    return {x, p - x};
  }

  int64_t z{0};
  for (int64_t k{1}; k < p; ++k) {
    if (!is_quadratic_residue(k, p)) {
      z = k;
      break;
    }
  }

  auto c{mod_pow(z, q, p)};
  auto r{mod_pow(n, (q + 1)/2, p)};
  auto t{mod_pow(n, q, p)};
  auto m{s};
  while (t != 1) {
    auto i{1};
    auto x{mod_mul(t, t, p)};
    while (x != 1) {
      x = mod_mul(x, x, p);
      i += 1;
    }
    const auto b{mod_pow(c, (1ll << (m - i - 1)), p)};
    r = mod_mul(r, b, p);
    c = mod_mul(b, b, p);
    t = mod_mul(t, c, p);
    m = i;
  }
  return {r, p - r};
}

std::tuple<int64_t, int64_t, int64_t> extended_gcd(int64_t a, int64_t b) {
  if (a == 0) return std::make_tuple(b, 0ll, 1ll);
  auto t = extended_gcd(b % a, a);
  auto g = std::get<0>(t);
  auto y = std::get<1>(t);
  auto x = std::get<2>(t);
  return std::make_tuple(g, x - (b/a)*y, y);
}

int64_t mod_inv(int64_t a, int64_t n) {
  auto result = extended_gcd(a, n);
  if (std::get<0>(result) == 1)
    return (n + std::get<1>(result)) % n;
  throw std::runtime_error("mod_inv args not coprime.");
}

template<typename T>
void cartesian_product_helper(
  std::vector<std::vector<T>> const& v,
  std::vector<std::vector<T>>& result,
  std::vector<T>& path,
  int i)
{
  if (i == v.size()) {
    result.push_back(path);
  } else {
    for (int j = 0; j < v[i].size(); ++j) {
      path.push_back(v[i][j]);
      cartesian_product_helper(v, result, path, i + 1);
      path.pop_back();
    }
  }
}

template<typename T>
std::vector<std::vector<T>> cartesian_product(std::vector<std::vector<T>> const& v) {
  std::vector<std::vector<T>> result;
  std::vector<T> path;
  result.reserve(50);
  cartesian_product_helper(v, result, path, 0);
  return result;
}

int64_t chinese_remainder_theorem(const std::vector<std::pair<int64_t, int64_t>>& pr) {
  int64_t m{1};
  for (int i{0}; i < pr.size(); ++i) {
    m *= pr[i].second;
  }

  int64_t x{0};
  for (int i{0}; i < pr.size(); ++i) {
    const auto a{pr[i].first};
    const auto pk{pr[i].second};
    const auto y0{m / pk};
    const auto y1{mod_inv(y0, pk)};
    x += mod_mul(mod_mul(a, y0, m), y1, m);
    if (x >= m) x -= m;
  }
  return x;
}

bool is_prime(int64_t n) {
  static std::vector<std::pair<int64_t, bool>> witnesses = {
    { 2, true}, { 3, true}, { 5, true},
    { 7, true}, {11, true}, {13, true},
    {17, true}, {19, true}, {23, true},
    {29, true}, {31, true}, {37, true}
  };

  if (n <= 3) return n >= 2;
  if (~n & 1) return false;

  for (auto const& a_pair : witnesses) {
    if (n == a_pair.first) return a_pair.second;
  }

  int64_t s{0};
  int64_t d{n - 1};
  while (~d & 1) {
    d >>= 1;
    ++s;
  }

  for (auto const& a_pair : witnesses) {
    const auto a = a_pair.first;
    if (mod_pow(a, d, n) != 1) {
      bool ok{true};
      auto x = mod_pow(a, d, n);
      for (int64_t r{0}; r < s; ++r) {
        if (x == n - 1) {
          ok = false;
          break;
        }
        x = mod_mul(x, x, n);
      }
      if (ok) return false;
    }
  }
  return true;
}

int64_t smallest_prime_factor(int64_t n) {
  static const int64_t sieve_limit = 20000000;
  static std::vector<int64_t> smf;
  static std::vector<int64_t> primes;

  // Perform the sieve on the first
  // call to this function.
  if (smf.size() == 0) {
    smf.resize(sieve_limit + 1);
    std::fill(smf.begin(), smf.end(), sieve_limit);
    std::vector<bool> composite(sieve_limit + 1, false);
    composite[0] = composite[1] = true;
    smf[0] = smf[1] = 1;
    for (int64_t i{2}; i <= sieve_limit; ++i) {
      if (!composite[i]) {
        primes.push_back(i);
        smf[i] = i;
        for (int64_t j{2*i}; j <= sieve_limit; j += i) {
          composite[j] = true;
          smf[j] = std::min(smf[j], i);
        }
      }
    }
  }

  if (n <= sieve_limit) return smf[n];

  if (is_prime(n)) return n;

  // Try small primes.
  for (auto p : primes) {
    if (n % p == 0) return p;
  }

  int64_t p = sieve_limit + ((sieve_limit & 1)? 0 : 1);
  while (n % p) p += 2;
  return p;
}

std::vector<std::pair<int64_t, int64_t>> factorize(int64_t n) {
  std::vector<std::pair<int64_t, int64_t>> result;
  result.reserve(9);
  while (n > 1) {
    int64_t p{smallest_prime_factor(n)};
    int64_t e{0};
    while (n % p == 0) {
      n /= p;
      ++e;
    }
    result.push_back(std::make_pair(p, e));
  }
  return result;
}

int64_t ipow(int64_t a, int64_t b) {
  if (b == 0) return 1;
  else if (b & 1) return a*ipow(a, b - 1);
  else return ipow(a*a, b >> 1);
}

std::set<long long> IntModulo::sqrt(unsigned long long modulus) const {
  int64_t a = this->get_num();
  int64_t n = modulus;

    static std::map<std::pair<int64_t, int64_t>, std::set<int64_t>> memo;
    if (n < 1) return {};
    if (n == 1) return {0ll};

    a %= n;
  const auto pr = std::make_pair(a, n);
  const auto it = memo.find(pr);
  if (it != memo.end()) return it->second;

  if (gcd(a, n) == 1) {
      if (is_power_of_two(n)) {
        if (a % std::min(n, int64_t{8}) == 1) {
          int64_t k{0};
          int64_t t{n};
          while (t > 1) {
            t >>= 1;
            k += 1;
          }
          if (k == 1) return memo[pr] = {int64_t{1}};
          if (k == 2) return memo[pr] = {int64_t{1}, int64_t{3}};
          if (k == 3) return memo[pr] = {int64_t{1}, int64_t{3}, int64_t{5}, int64_t{7}};
          if (a == 1)
            return memo[pr] = {int64_t{1}, (n >> 1) - 1ll, (n >> 1) + 1ll, n - 1ll};

          std::set<int64_t> roots;
          for (const auto x : IntModulo(a).sqrt(n >> 1)) {
            const int64_t i = ((x*x - a) >> (k - 1)) & 1;
            const int64_t r = x + (i << (k - 2));
            roots.insert(r);
            roots.insert(n - r);
          }
          return memo[pr] = roots;
        }
      } else if (is_prime(n)) {
        std::set<int64_t> roots;
        for (const auto& r : tonelli_shanks(a, n)) {
          roots.insert(r);
        }
        return memo[pr] = roots;
      } else {
        const auto pe = factorize(n);

        if (pe.size() == 1) {
          int64_t p{pe[0].first};
          int64_t k{pe[0].second};

          auto roots = tonelli_shanks(a, p);
          int64_t pk{p};
          int64_t pi{p*p};
          for (int i{2}; i <= k; ++i) {
            const int64_t x{roots[0]};
            const int64_t y{mod_mul(mod_inv(2, pk), mod_inv(x, pk), pk)};
            roots[0] = (pi + x - mod_mul(mod_mul(x, x, pi) - a + pi, y, pi)) % pi;
            roots[1] = pi - roots[0];
            pk *= p;
            pi *= p;
          }
          return memo[pr] = {roots[0], roots[1]};
        } else {
          std::vector<std::vector<std::pair<int64_t, int64_t>>> solutions(pe.size());
          for (int i{0}; i < pe.size(); ++i) {
            const auto m = ipow(pe[i].first, pe[i].second);
            const auto r = IntModulo(a).sqrt(m);
            solutions[i].reserve(r.size());
            for (auto&& r0 : r) {
              solutions[i].push_back(std::make_pair(r0, m));
            }
          }
          const auto cp = cartesian_product(solutions);
          std::set<int64_t> roots;
          for (auto&& p : cp) {
            roots.insert(chinese_remainder_theorem(p));
          }
          return memo[pr] = roots;
        }
      }
    }
    // No solutions.
    return {};
}
