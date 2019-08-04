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
using namespace std;
#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)

int ordnum(int n)
{
    int ret = 0;
    while (n != 0)
    {
        ret++;
        n /= 10;
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> h(n, 0);
    rep(i, n) cin >> h[i];

    int cmax = -1;
    bool minus = false;
    rep(i, n)
    {
        if (cmax <= h[i])
        {
            cmax = h[i];
        }
        else
        {
            if (cmax <= h[i] + 1)
            {
                cmax = h[i] + 1;
            }
            else
            {
                cout
                    << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}