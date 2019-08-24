#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
const long long INF = 1LL << 60;
using namespace std;

int main(int argc, char const *argv[])
{
    ll n, c;
    cin >> n >> c;
    ll last = n - 1;
    ll x[n], v[n];
    rep(i, n) cin >> x[i] >> v[i];
    ll sushir[n], sushil[n];
    sushir[0] = v[0];
    rep(i, 1, n) sushir[i] = sushir[i - 1] + v[i];

    sushil[last] = v[last];
    rep(i, 1, n) sushil[last - i] = sushil[last - i + 1] + v[last - i];

    ll sumr[n], suml[n];
    rep(i, n) sumr[i] = sushir[i] - x[i];
    rep(i, n) suml[last - i] = sushil[last - i] - (c - x[last - i]);

    ll posr[n], posl[n];
    ll bestr[n], bestl[n];
    bestr[0] = max(0ll, sumr[0]);
    posr[0] = x[0];

    rep(i, 1, n) if (bestr[i - 1] < sumr[i])
    {
        bestr[i] = sumr[i];
        posr[i] = x[i];
    }
    else
    {
        bestr[i] = bestr[i - 1];
        posr[i] = posr[i - 1];
    }

    bestl[n - 1] = max(0ll, suml[n - 1]);
    posl[last] = x[last];
    rep(i, 1, n) if (bestl[last - i + 1] < suml[last - i])
    {
        bestl[last - i] = suml[last - i];
        posl[last - i] = c - x[last - i];
    }
    else
    {
        bestl[last - i] = bestl[last - i + 1];
        posl[last - i] = posl[last - i + 1];
    };

  /*  rep(i, n) cerr << "sushiR" << i << ":" << sushir[i] << endl;
    rep(i, n) cerr << "sushiL" << i << ":" << sushil[i] << endl;
    rep(i, n) cerr << "sumR" << i << ":" << sumr[i] << endl;
    rep(i, n) cerr << "sumL" << i << ":" << suml[i] << endl;
    rep(i, n) cerr << "bestR" << i << ":" << bestr[i] << endl;
    rep(i, n) cerr << "bestL" << i << ":" << bestl[i] << endl;
    rep(i, n) cerr << "posR" << i << ":" << posr[i] << endl;
    rep(i, n) cerr << "posL" << i << ":" << posl[i] << endl;
*/
    ll ans = 0;
    rep(i, n - 1)
    {
        cerr << bestr[i] << " " << bestl[i + 1] << endl;
        ans = max(ans, bestr[i] + bestl[i + 1] - min(posr[i], posl[i + 1]));
        ans = max(ans, bestr[i]);
        ans = max(ans, bestl[i + 1]);
    }
    cout << ans << endl;
    return 0;
}
