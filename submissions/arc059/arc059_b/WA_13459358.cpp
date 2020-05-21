#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
random_device rnd;
mt19937 mt(rnd());
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;
int n;
int main()
{
    string s;
    cin >> s;
    if (s.size() == 2)
    {
        if (s[0] == s[1])
        {
            cout << -1 << " " << -1 << endl;
        }
        else
        {
            cout << 1 << " " << 2 << endl;
        }
    }
    else
    {
        rep(i, s.size() - 2)
        {
            if (s[i] == s[i + 1] || s[i] == s[i + 2] || s[i + 1] == s[i + 2])
            {
                cout << i + 1 << " " << i + 3 << endl;
                return 0;
            }
        }
    }

    cout << -1 << " " << -1 << endl;
    return 0;
}