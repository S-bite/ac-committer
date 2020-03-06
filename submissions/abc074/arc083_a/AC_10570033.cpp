#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{
    int a, b, c, d, e, f;
    int n = 3010;
    cin >> a >> b >> c >> d >> e >> f;
    vector<bool> makableWater(n, false);
    vector<bool> makableSugar(n, false);
    makableSugar[0] = true;
    makableWater[0] = true;
    rep(i, n)
    {
        if (i + a < n)
        {
            makableWater[i + a] = makableWater[i + a] || makableWater[i];
        }
        if (i + b < n)
        {
            makableWater[i + b] = makableWater[i + b] || makableWater[i];
        }
    }
    rep(i, n)
    {
        if (i + c < n)
        {
            makableSugar[i + c] = makableSugar[i + c] || makableSugar[i];
        }
        if (i + d < n)
        {
            makableSugar[i + d] = makableSugar[i + d] || makableSugar[i];
        }
    }
    int bestWater = 0;
    int bestSugar = 0;
    lld density = -1;
    rep(i, 1, n) rep(j, n)
    {
        if (makableWater[i] == false || makableSugar[j] == false)
            continue;
        if (100 * i + j <= f && i * e >= j)
        {
            lld tmp = ((lld)100 * j) / (100 * i + j);
            if (tmp > density)
            {
                density = tmp;
                bestWater = i * 100 + j;
                bestSugar = j;
            }
        }
    }
    cout << bestWater << " " << bestSugar << endl;
    return 0;
}
