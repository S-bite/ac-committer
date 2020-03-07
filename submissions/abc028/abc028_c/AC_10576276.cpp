#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#define chmin(x, y) x = min(x, y);
using namespace std;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int choose(vector<int> &v, int p)
{
    int ret = 0;
    rep(i, 5)
    {
        if (((p >> i) & 1) == 1)
        {
            ret += v[i];
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    vector<int> v(5);
    rep(i, 5) cin >> v[i];
    vector<int> w;
    rep(i, (1 << 5) - 1)
    {

        if (__builtin_popcount(i) != 3)
            continue;
        w.push_back(choose(v, i));
    }
    sort(ALL(w), greater<int>());
    cout << w[2] << endl;
    return 0;
}
