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

    int n, d, k;
    cin >> n >> d >> k;
    vector<int> r(d), l(d);
    rep(i, d) cin >> l[i] >> r[i];
    rep(i, k)
    {
        int s, t;
        cin >> s >> t;
        int cur = s;
        rep(j, d)
        {
            if (s < t)
            {
                if (l[j] <= cur && cur < r[j])
                {
                    cur = r[j];
                }
                if (t <= cur)
                {
                    cout << j + 1 << endl;
                    break;
                }
            }
            else
            {
                if (l[j] < cur && cur <= r[j])
                {
                    cur = l[j];
                }
                if (cur <= t)
                {
                    cout << j + 1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
