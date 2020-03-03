#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using P = pair<int, int>;

const int IINF = 1 << 29;
const ll INF = 1ll << 60;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    VI imos(1000001, 0);
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        imos[a]++;
        imos[b + 1]--;
    }
    int ans = -1;
    int cur = 0;
    rep(i, 1000001)
    {
        cur += imos[i];
        ans = max(ans, cur);
    }
    cout << ans << endl;

    return 0;
}
