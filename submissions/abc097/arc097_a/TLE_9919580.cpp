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
    string s;
    cin >> s;
    int k;
    cin >> k;
    k--;
    map<string, bool> mp;
    vector<string> v;
    rep(i, s.size())
    {
        rep(j, 1, s.size() - i + 1)
        {
            string t = s.substr(i, j);
            if (mp[t] == true)
            {
                continue;
            }
            mp[t] = true;
            v.push_back(t);
        }
    }
    sort(ALL(v));
    cout << v[k] << endl;
    return 0;
}
