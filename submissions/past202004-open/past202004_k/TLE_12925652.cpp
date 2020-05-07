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

VL a(3005);
VL b(3005);

VVL memo(3005, VL(3005, INF));
string s;
ll dfs(int l, int r)
{
    if (l > r)
        return 0;
    if (l == r)
    {
        memo[l][r] = b[r];
        return b[r];
    }
    if (memo[l][r] != INF)
        return memo[l][r];
    assert(l < r);
    if (l + 1 == r)
    {
        if (s[l] == '(' && s[r] == ')')
        {
            memo[l][r] = 0;
        }
        else if (s[l] == ')' && s[r] == ')')
        {
            memo[l][r] = min(a[l], b[l] + b[r]);
        }
        else if (s[l] == '(' && s[r] == '(')
        {
            memo[l][r] = min(a[r], b[l] + b[r]);
        }
        else
        {
            memo[l][r] = min(a[l] + a[r], b[l] + b[r]);
        }
        return memo[l][r];
    }
    memo[l][r] = min(dfs(l + 1, r) + b[l], dfs(l, r - 1) + b[r]);
    ll lcost = (s[l] == '(' ? 0 : a[l]);
    for (int i = l + 1; i <= r; i++)
    {
        ll icost = (s[i] == ')' ? 0 : a[i]);
        chmin(memo[l][r], lcost + icost + dfs(l + 1, i - 1) + dfs(i + 1, r));
    }
    return memo[l][r];
}

int main()
{
    int n;
    cin >> n;
    cin >> s;
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n)
    {
        cin >> b[i];
    }
    cout << dfs(0, n - 1) << endl;
    return 0;
}