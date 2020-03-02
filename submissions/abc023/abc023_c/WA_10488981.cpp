#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
int main(int argc, char const *argv[])
{
    int r, c, k, n;
    cin >> r >> c >> k >> n;
    map<int, int> mp1, mp2;
    map<int, vector<int>> mmp1, mmp2;
    vector<pair<int, int>> p(n);
    vector<int> sum1(r, 0), sum2(c, 0);

    rep(i, n)
    {
        cin >> p[i].first >> p[i].second;
        p[i].first--;
        p[i].second--;
    }
    rep(i, n)
    {
        sum1[p[i].first]++;
        sum2[p[i].second]++;
        mmp1[p[i].first].push_back(p[i].second);
        mmp2[p[i].second].push_back(p[i].first);
    }
    rep(i, r)
    {
        mp1[sum1[i]]++;
    }
    rep(i, c)
    {
        mp2[sum2[i]]++;
    }
    int ans = 0;
    rep(i, r)
    {
        int cur = 0;
        int rnum = sum1[i];
        int rem = k - rnum;
        if (rem < 0)
            continue;
        cur += mp2[rem];
        for (auto x : mmp1[i])
        {
            if (sum2[x] == rem)
            {
                cur--;
            }
            else if (sum2[x] == rem + 1)
            {
                cur++;
            }
        }
        ans += max(0, cur);
    }
    cout << ans << endl;
    return 0;
}
