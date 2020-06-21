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

int main()
{

    ll n;
    cin >> n;
    //n--;
    VI v;
    while (n != 0)
    {
        if (n % 26)
        {
        }
        v.push_back(n % 26);
        n /= 26;
    }
    rep(i, v.size() - 1)
    {
        if (v[i] <= 0)
        {
            v[i] += 26;
            v[i + 1]--;
        }
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] <= 0)
        {
            continue;
        }
        //cerr << v[i] << endl;
        cout << (char)('a' + v[i] - 1);
    }
    cout << endl;
    return 0;
}