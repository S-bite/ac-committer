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
    int n;
    cin >> n;
    vector<int> v1(n), v2;
    rep(i, n)
    {
        cin >> v1[i];
    }
    v2 = v1;
    sort(ALL(v2));
    map<int, int> mp;
    map<int, bool> used;
    int cur = 0;
    rep(i, n)
    {
        if (used[v2[i]] == false)
        {
            mp[v2[i]] = cur;
            cur++;
            used[v2[i]] = true;
        }
    }
    rep(i, n)
    {
        cout << mp[v1[i]] << endl;
    }
    return 0;
}