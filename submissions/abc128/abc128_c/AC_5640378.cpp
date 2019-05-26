#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <bitset>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;
int main(int argc, char const *argv[])
{

    int n, m;
    cin >> n >> m;
    int k[m];
    vector<int> v[m];
    int p[m];
    rep(i, m)
    {
        cin >> k[i];
        rep(j, k[i])
        {
            int t;
            cin >> t;
            v[i].push_back(t - 1);
        }
    }
    rep(i, m) cin >> p[i];
    ll ans = 0;
    rep(i, 1 << (n))
    {
        bool all = true;
        rep(j, m)
        {
            int ok = 0;
            rep(l, v[j].size())
            {
                if (((i >> v[j][l]) & 1) == 1)
                    ok ^= 1;
            }
            //  cerr << ok << endl;
            if (ok != p[j])
            {
                all = false;
                break;
            }
        }
        if (all == true)
        {
            //   cerr << bitset<8>(i) << endl;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
