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
vector<ll> ans;

bool ok(ll n, ll k)
{
    assert(2 <= k && k <= n);
    while (n % k == 0)
        n /= k;
    return n % k == 1ll;
}

vector<ll> prime;
void initprime()
{
    prime.push_back(2);
    rep(i, 3, 1010101)
    {
        bool isprime = true;
        rep(j, prime.size())
        {
            if (prime[j] * prime[j] > i)
            {
                break;
            }
            if (i % prime[j] == 0)
            {
                isprime = false;
                break;
            }
        }
        if (isprime)
        {
            prime.push_back(i);
        }
    }
}

int main()
{
    initprime();
    ll n;
    cin >> n;
    ll ans = 1;
    ll cur = 0;
    rep(i, n)
    {
        if (prime[i] * prime[i] > n)
            break;
        cur = prime[i];
        ll num = 1;
        while (ok(n, cur))
        {
            cur *= prime[i];
            num++;
        }
        if (num > 1)
        {
            ans *= num;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
