#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
const ll MOD = 1000000007;
using namespace std;

int calc(vector<int> s, int l[2], int r[2])
{

    int ret = 0;
    rep(i, s.size())
    {
        if (i + 1 == s.size())
        {
            ret++;
            continue;
        }
        if (s[i] == l[0] && s[i + 1] == l[1])
        {
            i++;
        }
        else if (s[i] == r[0] && s[i + 1] == r[1])
        {
            i++;
        }
        ret++;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> t;
    rep(i, s.size())
    {
        if (s[i] == 'A')
        {
            t.push_back(0);
        }
        else if (s[i] == 'B')
        {
            t.push_back(1);
        }
        else if (s[i] == 'X')
        {
            t.push_back(2);
        }
        else if (s[i] == 'Y')
        {
            t.push_back(3);
        }
    }
    int l[2], r[2];

    int ans = 10000;
    rep(i, 16)
    {
        rep(j, 16)
        {
            l[0] = i / 4;
            l[1] = i % 4;
            r[0] = j / 4;
            r[1] = j % 4;
            ans = min(ans, calc(t, l, r));
        }
    }
    cout << ans << endl;
    return 0;
}
