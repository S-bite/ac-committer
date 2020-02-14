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
    ll h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    map<pair<int, int>, bool> mp;
    ll ng = 0;
    rep(i, n)
    {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        mp[{r, c}] = true;
        if (r > 0)
        {
            if (mp[{r - 1, c}] == false)
            {
                ng++;
            }
        }
        if (c > 0)
        {
            if (mp[{r, c - 1}] == false)
            {
                ng++;
            }
        }
        if (r + 1 < h)
        {
            if (mp[{r + 1, c}] == false)
            {
                ng++;
            }
        }
        if (c + 1 < w)
        {
            if (mp[{r, c + 1}] == false)
            {
                ng++;
            }
        }
    }
    cout << (w - 1) * h + (h - 1) * w - ng << endl;
    return 0;
}
