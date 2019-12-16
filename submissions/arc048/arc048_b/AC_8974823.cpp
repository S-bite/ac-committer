#include <bits/stdc++.h>
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

vector<int> calc_score(vector<vector<int>> &p, int r, int h)
{
    vector<int> ret(3, 0); // win lose draw
    ret[0] += max((lower_bound(ALL(p[h]), r) - p[h].begin()), 0l);

    ret[0] += max((upper_bound(ALL(p[(h + 1) % 3]), r) - p[(h + 1) % 3].begin()), 0l);

    ret[0] += max((lower_bound(ALL(p[(h + 2) % 3]), r) - p[(h + 2) % 3].begin()), 0l);

    ret[1] += p[h].end() - (upper_bound(ALL(p[h]), r));
    ret[1] += p[(h + 1) % 3].end() - (upper_bound(ALL(p[(h + 1) % 3]), r));
    ret[1] += p[(h + 2) % 3].end() - (lower_bound(ALL(p[(h + 2) % 3]), r));

    ret[2] += upper_bound(ALL(p[h]), r) - lower_bound(ALL(p[h]), r) - 1;

    return ret;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<int>> p(3);
    map<int, pair<int, int>> mp;
    rep(i, n)
    {
        int r, h;
        cin >> r >> h;
        h--;
        p[h].push_back(r);
        mp[i] = {r, h};
    }
    sort(ALL(p[0]));
    sort(ALL(p[1]));
    sort(ALL(p[2]));
    rep(i, n)
    {
        auto ret = calc_score(p, mp[i].first, mp[i].second);
        cout << ret[0] << " " << ret[1] << " " << ret[2] << endl;
    }
    return 0;
}
