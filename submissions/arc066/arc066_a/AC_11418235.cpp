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

const ll MOD = 1000000000 + 7;

ll mpow(int base, int n)
{
    if (n == 0)
        return 1;
    ll prev = mpow(base, n / 2);
    if (n % 2 == 0)
    {
        return (prev * prev) % MOD;
    }
    else
    {
        return (prev * prev * base) % MOD;
    }
}

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    rep(i, n)
    {
        int a;
        cin >> a;
        mp[a]++;
    }
    int i = n - 1;
    while (i > 0)
    {
        cerr << i << endl;

        if (mp[i] != 2)
        {
            cout << 0 << endl;
            return 0;
        }
        i -= 2;
    }
    cout << mpow(2, n / 2) << endl;
    return 0;
}
