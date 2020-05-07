#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
random_device rnd;
mt19937 mt(rnd());

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int ans = 0;

bool match(string &t, string &s)
{
    if (t == "")
        return false;
    if (t.size() > s.size())
        return false;
    rep(i, 1 + ((int)s.size() - t.size()))
    {
        bool ok = true;
        rep(j, t.size())
        {
            ok &= (t[j] == '.' || t[j] == s[i + j]);
        }
        if (ok)
            return true;
    }
    return false;
}

void dfs(string cur, string &s)
{
    if (cur.size() >= 4)
        return;
    if (match(cur, s))
    {
        //cerr << cur << endl;
        ans++;
    }
    dfs(cur + ".", s);
    for (char c = 'a'; c <= 'z'; c++)
    {
        dfs(cur + c, s);
    }
}

int main()
{
    string s;
    cin >> s;
    dfs("", s);
    cout << ans << endl;
    return 0;
}