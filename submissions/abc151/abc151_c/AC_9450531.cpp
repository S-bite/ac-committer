#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    map<int, bool> mp;
    map<int, int> mpp;

    int ac = 0, pena = 0;
    rep(i, m)
    {
        int p;
        string s;
        cin >> p >> s;
        if (s == "AC")
        {
            if (mp[p] == false)
            {
                ac++;
                mp[p] = true;
            }
        }
        else
        {
            if (mp[p] == false)
            {
                mpp[p]++;
            }
        }
    }
    rep(i, n + 1)
    {
        if (mp[i] == true)
        {
            pena += mpp[i];
        }
    }
    cout << ac << " " << pena << endl;
    return 0;
}