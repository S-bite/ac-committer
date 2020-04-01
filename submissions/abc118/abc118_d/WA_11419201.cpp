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
int num[10] = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};

map<int, bool> canuse;

string bigger(string &s, string &t)
{
    if (s.size() > t.size())
    {
        return s;
    }
    if (s.size() < t.size())
    {
        return t;
    }
    return max(s, t);
}

int main()
{
    int n, m;
    cin >> n >> m;
    rep(i, m)
    {
        int x;
        cin >> x;
        canuse[x] = true;
    }
    vector<string> dp(n + 1, "");
    rep(i, n)
    {
        rep(j, 10)
        {
            if (canuse[j] == false)
                continue;
            if (i + num[j] <= n)
            {
                string newstr = dp[i] + (char)('0' + j);
                //cerr << i + num[j] << " " << newstr << endl;
                dp[i + num[j]] = bigger(dp[i + num[j]], newstr);
            }
        }
    }
    sort(ALL(dp[n]), greater<char>());
    cout << dp[n] << endl;
    return 0;
}