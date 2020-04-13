#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
random_device rnd;
mt19937 mt(rnd());
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;

ll mpow(ll base, ll n) {
  if (n == 0)
    return 1;
  ll prev = mpow(base, n / 2);
  if (n % 2 == 0)
    return (prev * prev) % MOD;
  else
    return (((prev * prev) % MOD) * base) % MOD;
}

int main() {
  ll n, k;
  cin >> n >> k;
  map<ll, ll> mp;
  for (ll i = k; i >= 1; i--) {
    mp[i] = mpow(k / i, n);
    ll p = 2;
    while (p * i <= k) {
      mp[i] -= mp[p * i];
      if (mp[i] < 0)
        mp[i] += MOD;
      assert(mp[i] >= 0);
      p++;
    }
  }
  ll ans = 0;
  rep(i, 1, k + 1) {
    // cerr << i << " " << mp[i] << endl;
    ans += (ll)i * mp[i];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
