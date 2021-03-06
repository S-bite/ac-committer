#pragma GCC optimize("Ofast")
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

const ll INF = 1ll << 60;

int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    reverse(ALL(s));
    int cur = 0;
    vector<int> ans;
    while (cur != n)
    {
        //cerr << cur << endl;
        bool change = false;
        for (int i = m; i >= 1; i--)
        {
            if (cur + i <= n && s[cur + i] == '0')
            {
                cur += i;
                change = true;
                ans.push_back(i);
                break;
            }
        }
        if (change == false)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cerr << ans.size() << endl;
    reverse(ALL(ans));
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}