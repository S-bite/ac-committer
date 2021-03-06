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

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        while (i < j && s[i] == 'R')
            i++;
        if (i == j)
            break;
        while (i < j && s[j] == 'W')
            j--;
        if (i == j)
            break;
        ans++;
        s[i] = 'R';
        s[j] = 'W';
    }
    cout << ans << endl;

    return 0;
}