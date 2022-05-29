#include "sqrt.h"

#include <set>
#include <cstdint>
#include <map>
#include <algorithm>
#include <vector>
#include "../task5/pollardfactorization.h"

using ll = long long;

ll gcd(ll a, ll b) {
  while (b) {
    auto t = b;
    b = a % b;
    a = t;
  }
  return a;
}

std::tuple<ll, ll, ll> extended_gcd(ll a, ll b) {
  if (a == 0) return std::make_tuple(b, 0ll, 1ll);
  auto t = extended_gcd(b % a, a);
  auto g = std::get<0>(t);
  auto y = std::get<1>(t);
  auto x = std::get<2>(t);
  return std::make_tuple(g, x - (b/a)*y, y);
}

bool is_power_of_two(ll n) {
  return (n & (n - 1)) == 0;
}

ll mod_mul(ll a, ll b, ll m) {
  IntModulo k(a);
  k.multiply(IntModulo(b), m);
  return k.get_num();
}

ll mod_pow(ll a, ll b, ll m) {
  IntModulo k(a);
  k.pow(b, m);
  return k.get_num();
}

ll legendre_symbol(ll a, ll p) {
  return mod_pow(a, (p - 1)/2, p);
}

ll is_quadratic_residue(ll a, ll p) {
  return legendre_symbol(a, p) == 1;
}

std::vector<ll> tonelli_shanks(ll n, ll p) {
  if (!is_quadratic_residue(n, p)) return {};

  ll q{p - 1};
  ll s{0};
  while (~q & 1) {
    q >>= 1;
    s += 1;
  }

  if (s == 1) {
    const auto x{mod_pow(n, (p + 1)/4, p)};
    return {x, p - x};
  }

  ll z{0};
  for (ll k{1}; k < p; ++k) {
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

ll mod_inv(ll a, ll n) {
  auto result = extended_gcd(a, n);
  if (std::get<0>(result) == 1)
    return (n + std::get<1>(result)) % n;
  throw std::runtime_error("mod_inv args not coprime.");
}

void cartesian_product_helper(
  std::vector<std::vector<std::pair<ll, ll>>> const& v,
  std::vector<std::vector<std::pair<ll, ll>>>& result,
  std::vector<std::pair<ll, ll>>& path,
  size_t i)
{
  if (i == v.size()) {
    result.push_back(path);
  } else {
    for (size_t j = 0; j < v[i].size(); ++j) {
      path.push_back(v[i][j]);
      cartesian_product_helper(v, result, path, i + 1);
      path.pop_back();
    }
  }
}

std::vector<std::vector<std::pair<ll, ll>>> cartesian_product(std::vector<std::vector<std::pair<ll, ll>>> const& v) {
  std::vector<std::vector<std::pair<ll, ll>>> result;
  std::vector<std::pair<ll, ll>> path;
  result.reserve(50);
  cartesian_product_helper(v, result, path, 0);
  return result;
}

ll chinese_remainder_theorem(const std::vector<std::pair<ll, ll>>& pr) {
  ll m{1};
  for (size_t i{0}; i < pr.size(); ++i) {
    m *= pr[i].second;
  }

  ll x{0};
  for (size_t i{0}; i < pr.size(); ++i) {
    const auto a{pr[i].first};
    const auto pk{pr[i].second};
    const auto y0{m / pk};
    const auto y1{mod_inv(y0, pk)};
    x += mod_mul(mod_mul(a, y0, m), y1, m);
    if (x >= m) x -= m;
  }
  return x;
}

std::vector<std::pair<ll, ll>> factorize(ll n) {
  std::vector<std::pair<ll, ll>> result;
  for (auto factor : PollardFactorization::factorize(n)) {
      result.push_back(std::make_pair(factor.first, factor.second));
  }
  return result;
}

ll ipow(ll a, ll b) {
  if (b == 0) return 1;
  else if (b & 1) return a*ipow(a, b - 1);
  else return ipow(a*a, b >> 1);
}

std::set<long long> IntModulo::sqrt(unsigned long long modulus) const {
  ll a = this->get_num();
  ll n = modulus;

    static std::map<std::pair<ll, ll>, std::set<ll>> memo;
    if (n < 1) return {};
    if (n == 1) return {0ll};

    a %= n;
  const auto pr = std::make_pair(a, n);
  const auto it = memo.find(pr);
  if (it != memo.end()) return it->second;

  if (gcd(a, n) == 1) {
      if (is_power_of_two(n)) {
        if (a % std::min(n, ll{8}) == 1) {
          ll k{0};
          ll t{n};
          while (t > 1) {
            t >>= 1;
            k += 1;
          }
          if (k == 1) return memo[pr] = {ll{1}};
          if (k == 2) return memo[pr] = {ll{1}, ll{3}};
          if (k == 3) return memo[pr] = {ll{1}, ll{3}, ll{5}, ll{7}};
          if (a == 1)
            return memo[pr] = {ll{1}, (n >> 1) - 1ll, (n >> 1) + 1ll, n - 1ll};

          std::set<ll> roots;
          for (const auto x : IntModulo(a).sqrt(n >> 1)) {
            const ll i = ((x*x - a) >> (k - 1)) & 1;
            const ll r = x + (i << (k - 2));
            roots.insert(r);
            roots.insert(n - r);
          }
          return memo[pr] = roots;
        }
      } else if (IntModulo(n).isPrime(6)) {
        std::set<ll> roots;
        for (const auto& r : tonelli_shanks(a, n)) {
          roots.insert(r);
        }
        return memo[pr] = roots;
      } else {
        const auto pe = factorize(n);

        if (pe.size() == 1) {
          ll p{pe[0].first};
          ll k{pe[0].second};

          auto roots = tonelli_shanks(a, p);
          ll pk{p};
          ll pi{p*p};
          for (int i{2}; i <= k; ++i) {
            const ll x{roots[0]};
            const ll y{mod_mul(mod_inv(2, pk), mod_inv(x, pk), pk)};
            roots[0] = (pi + x - mod_mul(mod_mul(x, x, pi) - a + pi, y, pi)) % pi;
            roots[1] = pi - roots[0];
            pk *= p;
            pi *= p;
          }
          return memo[pr] = {roots[0], roots[1]};
        } else {
          std::vector<std::vector<std::pair<ll, ll>>> solutions(pe.size());
          for (size_t i{0}; i < pe.size(); ++i) {
            const auto m = ipow(pe[i].first, pe[i].second);
            const auto r = IntModulo(a).sqrt(m);
            solutions[i].reserve(r.size());
            for (auto&& r0 : r) {
              solutions[i].push_back(std::make_pair(r0, m));
            }
          }
          const auto cp = cartesian_product(solutions);
          std::set<ll> roots;
          for (auto&& p : cp) {
            roots.insert(chinese_remainder_theorem(p));
          }
          return memo[pr] = roots;
        }
      }
    }

    return {};
}
