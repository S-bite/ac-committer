#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = (1'000'000'000 + 7);
int h, w, k;
int popcnt(int n)
{
    int ret = 0;
    while (n != 0)
    {
        ret += (n & 1);
        n >>= 1;
    }
    return ret;
}
int calc(vector<string> &g, int split)
{
    int ret = 0;
    VI num(10, 0);
    bool isloop;
    rep(j, w)
    {
        //cerr << j << " " << split << endl;
        int mnum = -1;
        int cur = 0;
        rep(i, h)
        {
            if (g[i][j] == '1')
                num[cur]++;
            mnum = max(mnum, num[cur]);
            if (((split >> i) & 1) == 1)
            {
                cur++;
            }
        }
        if (mnum > k)
        {
            if (isloop)
            {
                return IINF;
            }
            //cerr << "split" << j << endl;
            ret++;
            rep(i, 10) num[i] = 0;
            j--;
            isloop = true;
        }
        else
        {

            isloop = false;
        }
    }
    //cerr << ret << endl;
    return ret;
}

int main()
{
    cin >> h >> w >> k;
    vector<string> g(h);
    rep(i, h) cin >> g[i];
    int ans = IINF;
    rep(split, (1 << (h - 1)))
    {
        ans = min(ans, popcnt(split) + calc(g, split));
    }
    cout << ans << endl;
    return 0;
}