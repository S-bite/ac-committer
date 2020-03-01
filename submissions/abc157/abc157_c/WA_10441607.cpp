#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
bool check(vector<pair<int, int>> &p, int n)
{
    vector<int> v;

    do
    {
        v.push_back(n % 10);
        n /= 10;
    } while (n != 0);
    reverse(ALL(v));
    for (auto x : p)
    {
        // cerr << v[x.first] << " " << x.second << endl;
        if (x.first + 1 > v.size() || v[x.first] != x.second)
        {
            return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    if (m == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<pair<int, int>> p;
    rep(i, m)
    {
        int s, c;
        cin >> s >> c;
        s--;
        p.push_back({s, c});
    }
    sort(ALL(p));
    if (p[0].second == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    rep(i, pow(10, n - 1), pow(10, n))
    {
        if (check(p, i))
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
