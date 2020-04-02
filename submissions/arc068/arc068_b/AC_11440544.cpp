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
    int n;
    cin >> n;
    map<int, int> mp;
    rep(i, n)
    {
        int t;
        cin >> t;
        mp[t]++;
    }
    int num2 = 0;
    int num1 = 0;
    int ans = mp.size();
    for (auto x : mp)
    {
        if (x.second % 2 == 0)
        {
            num2++;
        }
        else
        {
            num1++;
        }
    }
    if (num2 % 2 == 0)
    {
        cout << ans << endl;
    }
    else
    {
        cout << ans - 1 << endl;
    }

    return 0;
}