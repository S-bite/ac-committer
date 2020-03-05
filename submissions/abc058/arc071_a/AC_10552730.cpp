#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

vector<int> makevec(string &s)
{
    vector<int> ret(26, 0);
    rep(i, s.size())
    {
        ret[s[i] - 'a']++;
    }
    return ret;
}

vector<int> intersection(vector<int> v1, vector<int> v2)
{
    vector<int> ret(26, 0);
    rep(i, 26)
    {
        ret[i] = min(v1[i], v2[i]);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> ans(26, 1 << 29);
    rep(i, n)
    {
        string s;
        cin >> s;
        ans = intersection(ans, makevec(s));
    }
    rep(i, 26)
    {
        rep(j, ans[i])
        {
            cout << (char)('a' + i);
        }
    }
    cout << endl;

    return 0;
}