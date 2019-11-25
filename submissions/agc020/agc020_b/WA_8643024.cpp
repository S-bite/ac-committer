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
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    ll a[n];
    rep(i, n)
    {
        cin >> a[n - 1 - i];
    }
    int maxans = 2;
    int minans = 2;
    rep(i, n)
    {
        //cerr << i << " " << maxans << endl;
        if (maxans < a[i])
        {
            cout << -1 << endl;
            return 0;
        }
        int tmp = maxans;
        maxans = maxans + a[i] - 1;
        //assert(maxans - (maxans % a[i]) == tmp);
        while (a[i] * (maxans / a[i]) > tmp)
        {
            maxans--;
        }
        minans = a[i] * ((minans + a[i] - 1) / a[i]);
    }
    cout << minans << " " << maxans << endl;
    return 0;
}
