#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

string fillc(string s, char c)
{
    string ret = "";
    rep(i, s.size())
    {
        if (s[i] == '?')
        {
            ret += c;
        }
        else
        {
            ret += s[i];
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<string> v(n);
    rep(i, n) cin >> v[i];
    string s;
    cin >> s;
    int lownum = 0, highnum = 0;
    rep(i, n)
    {
        if (fillc(v[i], 'z') < s)
        {
            highnum++;
        }
        if (fillc(v[i], 'a') > s)
        {
            lownum++;
        }
    }
    for (int i = highnum; i < n - lownum + 1; i++)
    {
        cout << i + 1;
        if (i < n - lownum)
            cout << " ";
    }
    cout << endl;
    return 0;
}
