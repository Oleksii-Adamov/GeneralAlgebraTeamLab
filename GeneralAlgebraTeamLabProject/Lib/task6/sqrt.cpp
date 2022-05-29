#include "sqrt.h"

#include <random>
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

ll legendre_symbol(unsigned long long a, unsigned long long n)
{
    if (a == 1)
    {
        return 1;
    }
    if ((a % 2 == 0) && (a != 0))
    {
        return legendre_symbol(a / 2, n) * pow(-1, (n * n - 1) / 8);
    }
    if (a % 2 != 0)
    {
        return legendre_symbol(n % a, a) * pow(-1, (a - 1) * (n - 1) / 4);
    }
    return 0;
}


ll is_quadratic_residue(ll a, ll p) {
  return legendre_symbol(a, p) == 1;
}

std::set<long long> IntModulo::sqrt_prime(unsigned long long modulus) const {
    IntModulo a(*this);
    a.mod(modulus);

    if (modulus % 1 != 0)
        throw std::invalid_argument("modulus should be integer");

    if (legendre_symbol(a.get_num(), modulus) == -1)
        return {};

    // case p == 3 (mod 4) (Algorithm 3.36)
    if (modulus % 4 == 3) {
        IntModulo r(*this);
        r.pow((modulus+1)/4, modulus);
        IntModulo neg(r.get_num());
        neg.multiply(IntModulo(-1), modulus);
        return {r.get_num(), neg.get_num()};
    }

    // case p == 5 (mod 8) (Algorithm 3.37)
    if (modulus % 8 == 5) {
        IntModulo d(*this);
        d.pow((modulus-1)/4, modulus);
        IntModulo r(*this);
        if (d.get_num() == 1){
            r.pow((modulus+3)/8, modulus);
            IntModulo neg(r.get_num());
            neg.multiply(IntModulo(-1), modulus);
            return {r.get_num(), neg.get_num()};
        } else if ((unsigned) d.get_num() == modulus-1) {
            IntModulo r2(*this);
            r.multiply(IntModulo(2ll), modulus);
            r2.multiply(IntModulo(4ll), modulus);
            r2.pow((modulus-5)/8, modulus);
            r.multiply(r2, modulus);
            IntModulo neg(r.get_num());
            neg.multiply(IntModulo(-1), modulus);
            return {r.get_num(), neg.get_num()};
        }
    }

    // (Algorithm 3.34)

    // random numbers
    const int range_from  = 1;
    const int range_to    = modulus-1;

    std::random_device                        rand_dev;
    std::mt19937                              generator(rand_dev());
    std::uniform_int_distribution<long long>  distr(range_from, range_to);

    IntModulo b;

    do {
        b.set_num(distr(generator));
    } while (legendre_symbol(b.get_num(), modulus) != -1);

    IntModulo s(0);
    unsigned long long t = modulus - 1;

    while (t % 2 == 0 && s.get_num() < 10) {
        t /= 2;
        s.add(IntModulo(1), LLONG_MAX);
    }

    IntModulo rev = a.findReversed(modulus);

    IntModulo c;
    IntModulo temp(b);
    temp.pow(t, modulus);
    c.set_num(temp.get_num());

    IntModulo r(a.get_num());
    r.pow((t+1)/2, modulus);

    for (long long i = 1; i <= s.get_num()-1; i++)
    {
        IntModulo d(r);
        d.pow(2, modulus);
        d.multiply(rev, modulus);
        d.pow(std::pow(2, s.get_num()-i-1), modulus);

        if (modulus - d.get_num() == 1)
            r.multiply(c, modulus);

        c.pow(2, modulus);
    }

    IntModulo neg(r.get_num());
    neg.multiply(IntModulo(-1), modulus);
    return {r.get_num(), neg.get_num()};
}


ll mod_inv(ll a, ll n) {
  IntModulo k(a);
  return k.findReversed(n).get_num();
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
      if (is_power_of_two(n) || IntModulo(n).isPrime(6)) {
        std::set<ll> roots =this->sqrt_prime(n);
        return memo[pr] = roots;
      } else {
        const auto pe = factorize(n);

        if (pe.size() == 1) {
          ll p{pe[0].first};
          ll k{pe[0].second};

          auto roots_vec = IntModulo(a).sqrt_prime(p);
          std::vector<ll> roots(roots_vec.begin(), roots_vec.end());
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
