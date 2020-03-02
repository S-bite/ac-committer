#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

int diffnum(string s, string t)
{
    assert(s.size() == t.size());
    int ret = s.size();
    rep(i, s.size())
    {
        rep(j, t.size())
        {
            if (s[i] == t[j])
            {
                t[j] = '@';
                ret--;
                break;
            }
        }
    }
    return ret;
}

string rem(string s, string t)
{
    string ret;
    rep(i, s.size())
    {
        bool ok = false;
        rep(j, t.size())
        {
            if (s[i] == t[j])
            {
                t[j] = '@';
                ok = true;
                break;
            }
        }
        if (ok == false)
        {
            ret.push_back(s[i]);
        }
    }
    return ret;
}

//sの先頭をtにできるか
bool check(string s, string t, int k)
{
    rep(i, t.size())
    {
        if (s[i] != t[i])
            k--;
    }
    string r = rem(s, t);
    //cerr << s << " " << t << " " << r << endl;

    k -= diffnum(s.substr(t.size()), r);
    return k >= 0;
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string t = s.c_str();
    sort(ALL(t));
    string ans = "";
    vector<bool> used(n, false);
    rep(i, n)
    {
        rep(j, t.size())
        {
            if (used[j])
                continue;
            ans.push_back(t[j]);
            if (check(s, ans, k))
            {
                used[j] = true;
                break;
            }
            ans.pop_back();
        }
    }
    cout << ans << endl;

    return 0;
}
