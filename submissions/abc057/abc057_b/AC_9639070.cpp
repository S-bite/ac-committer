#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{

    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> students(n);
    vector<pair<ll, ll>> checkpoints(m);
    rep(i, n)
    {
        cin >> students[i].first >> students[i].second;
    }
    rep(i, m)
    {
        cin >> checkpoints[i].first >> checkpoints[i].second;
    }
    rep(i, n)
    {
        ll mindist = (1ll << 60);
        int ans = -1;
        rep(j, m)
        {
            ll curdist = labs(students[i].first - checkpoints[j].first) + labs(students[i].second - checkpoints[j].second);
            //cerr << i << " " << j << " " << curdist << endl;
            if (curdist < mindist)
            {
                mindist = curdist;
                ans = j;
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}
