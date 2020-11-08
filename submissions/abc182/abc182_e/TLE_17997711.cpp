#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const double EPS = 1e-3;
const double PI = 3.1415926535897932384626433832795028841971;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int main()
{
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<vector<int>> tate(w), yoko(h);
    vector<pair<int, int>> bulb;
    map<pair<int, int>, bool> mp;

    rep(i, n)
    {
        int y, x;
        cin >> y >> x;
        y--;
        x--;
        mp[{y, x}] = true;
        bulb.push_back({y, x});
    }
    rep(i, m)
    {
        int y, x;
        cin >> y >> x;
        y--;
        x--;
        tate[x].push_back(y);
        yoko[y].push_back(x);
    }
    rep(i, w)
    {
        tate[i].push_back(-1);
        tate[i].push_back(h);
        sort(ALL(tate[i]));
    }
    rep(i, h)
    {
        yoko[i].push_back(-1);
        yoko[i].push_back(w);
        sort(ALL(yoko[i]));
    }

    set<pair<int, int>> st;
    for (auto b : bulb)
    {

        int y = b.first;
        int x = b.second;
        // cerr << "!" << y + 1 << " " << x + 1 << endl;
        int start = *(lower_bound(ALL(tate[x]), y) - 1) + 1;

        int end = *(upper_bound(ALL(tate[x]), y)) - 1;
        for (int pos = start; pos <= end; pos++)
        {
            if (pos != -1 && pos != h)
            {
                // cerr << pos + 1 << " " << x + 1 << endl;
                st.insert({pos, x});
            }
        }
        start = *(upper_bound(ALL(yoko[y]), x) - 1) + 1;
        end = *(upper_bound(ALL(yoko[y]), x)) - 1;
        // cerr << start << " " << end << endl;
        for (int pos = start; pos <= end; pos++)
        {
            if (pos != -1 && pos != w)
            {
                //  cerr << y + 1 << " " << pos + 1 << endl;
                st.insert({y, pos});
            }
        }
    }
    //cerr << "ok" << endl;
    cout << (int)st.size() << endl;
    return 0;
}