#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()

using namespace std;
const lld eps = (1e-40);

lld dist(lld x1, lld y1, lld x2, lld y2)
{
    return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    int n;
    cin >> n;
    vector<lld> x(n);
    vector<lld> y(n);
    lld avgx = 0, avgy = 0;
    rep(i, n)
    {
        cin >> x[i] >> y[i];
        avgx += x[i];
        avgy += y[i];
    }
    avgx /= (lld)n;
    avgy /= (lld)n;
    lld ans = -1;
    lld p = 0.1;
    lld d, prevd;

    rep(i, 30000)
    {
        prevd = d;
        int bestid = 0;
        d = dist(avgx, avgy, x[0], y[0]);
        rep(j, n)
        {
            if (d < dist(avgx, avgy, x[j], y[j]))
            {
                d = dist(avgx, avgy, x[j], y[j]);
                bestid = j;
            }
        }
        avgx += (x[bestid] - avgx) * p;
        avgy += (y[bestid] - avgy) * p;

        p *= 0.999;
    }
    printf("%.10Lf\n", d);

    return 0;
}