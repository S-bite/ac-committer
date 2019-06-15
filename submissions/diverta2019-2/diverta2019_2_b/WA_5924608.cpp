#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#ifdef DEBUG
#define line() cout << "[" << __LINE__ << "] ";
#define dump(i) cout << #i ": " << i << " ";
#define dumpl(i) cout << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;

int main(int argc, char const *argv[])
{
#define int long long
    int n;
    cin >> n;
    pair<int, int> p[n];
    map<pair<int, int>, bool> g;

    rep(i, n)
    {
        cin >> p[i].first >> p[i].second;
        g[{p[i].first, p[i].second}] = true;
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    map<pair<int, int>, int> mp;

    rep(i, n)
    {
        rep(j, i + 1, n)
        {
            mp[{p[i].first - p[j].first, p[i].second - p[j].second}]++;
        }
    }
    int now = -1;
    int x = 0, y = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        int value = itr->second;
        auto key = itr->first;
        if (now < value)
        {
            now = value;
            x = key.first;
            y = key.second;
        }
    }
    bool flg = true;
    int ans = 0;
    while (flg)
    {
        flg = false;
        auto _g = g;
        for (auto itr = _g.begin(); itr != _g.end(); itr++)
        {
            auto key = itr->first;

            if (g[key] == true)
            {
                flg = true;
                int a = key.first, b = key.second;
                while (g[{a, b}])
                {
                    a += x;
                    b += y;
                }

                a -= x;
                b -= y;
                while (g[{a, b}])
                {
                    // cerr << "del" << a << "," << b << endl;
                    g[{a, b}] = false;
                    a -= x;
                    b -= y;
                }
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
