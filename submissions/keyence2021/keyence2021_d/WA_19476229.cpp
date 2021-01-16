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
const ll MOD = 998244353;

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        cout << "AB" << endl;
        return 0;
    }
    int num = lcm((1 << (n - 1) - 1), (1 << n) - 1);
    int shift = gcd((1 << (n - 1) - 1), (1 << n) - 1);
    string s = "";
    rep(i, 1 << (n - 1) - 1)
    {
        s += "A";
    }
    rep(i, 1 << (n - 1))
    {
        s += "B";
    }
    cout << num << endl;
    rep(i, num)
    {
        cout << "A" << s << endl;
        char tmp = s[0];
        rep(k, shift)
        {
            rep(j, s.size() - 1)
            {
                s[j] = s[j + 1];
            }
            s.back() = tmp;
        }
    }

    return 0;
}