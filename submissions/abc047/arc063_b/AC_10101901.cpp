#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    int vmin = (1 << 30);
    int bestpro = 0;
    int numpro = 0;
    rep(i, n)
    {
        int curpro = max(0, v[i] - vmin);
        cerr << curpro << endl;
        if (curpro == bestpro)
        {
            numpro++;
        }
        else if (curpro > bestpro)
        {
            bestpro = curpro;
            numpro = 1;
        }
        vmin = min(vmin, v[i]);
    }
    cout << numpro << endl;
    return 0;
}
