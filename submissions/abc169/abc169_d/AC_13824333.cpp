#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
random_device rnd;
mt19937 mt(rnd());

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

vector<int> Eratosthenes(const int N)
{
    vector<bool> is_prime(N + 1);
    for (int i = 0; i <= N; i++)
    {
        is_prime[i] = true;
    }
    vector<int> P;
    for (int i = 2; i <= N; i++)
    {
        if (is_prime[i])
        {
            for (int j = 2 * i; j <= N; j += i)
            {
                is_prime[j] = false;
            }
            P.emplace_back(i);
        }
    }
    return P;
}
int calc(int x)
{
    int cur = 1;
    while (((cur + 1) * cur) / 2 <= x)
    {
        cur++;
    }
    cur--;
    return cur;
}
int main()
{
    ll n;
    cin >> n;
    int ans = 0;
    ll x = 2;
    cerr << "done" << endl;
    while (x * x <= n)
    {
        if (n % x == 0)
        {
            int cnt = 0;
            while (n % x == 0)
            {
                cnt++;
                n /= x;
            }
            // cerr << cnt << " " << calc(cnt) << endl;
            ans += calc(cnt);
        }
        x++;
    }
    if (n != 1)
    {
        ans++;
    }
    cout << ans << endl;
    return 0;
}