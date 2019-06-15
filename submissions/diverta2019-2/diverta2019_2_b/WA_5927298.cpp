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
    //    sort(p, p + n);
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
            int k = 1;
            if (p[i].first - p[j].first < 0)
            {
                k = -1;
            }
            mp[{k * (p[i].first - p[j].first), k * (p[i].second - p[j].second)}]++;
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
    cout << n - now << endl;
    return 0;
}
