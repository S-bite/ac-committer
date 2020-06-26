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

ll pow(ll base, ll num)
{
    if (num == 0)
        return 1;
    ll prev = pow(base, num / 2);
    if (prev * prev > 1000000000)
    {
        cout << "large" << endl;
        exit(0);
    }

    if (num % 2 == 0)
    {
        return prev * prev;
    }
    else
    {
        if (prev * prev * base > 1000000000)
        {
            cout << "large" << endl;
            exit(0);
        }
        return prev * prev * base;
    }
}

int main()
{
    ll a, r, n;
    cin >> a >> r >> n;
    ll m = pow(r, n - 1);
    if (a * m > 1000000000)
    {
        cout << "large" << endl;
        exit(0);
    }
    cout << a * m << endl;
    return 0;
}
