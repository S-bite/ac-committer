#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const ll INF = 1ll << 60;

int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n)
    {
        cin >> v[i];
    }
    rep(i, n)
    {
        if (v[i] % 2 == 0)
        {
            if (v[i] % 3 != 0 && v[i] % 5 != 0)
            {
                cout << "DENIED" << endl;
                return 0;
            }
        }
    }
    cout << "APPROVED" << endl;
    return 0;
}