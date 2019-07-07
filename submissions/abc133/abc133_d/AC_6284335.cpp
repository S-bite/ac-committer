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
    int l[n];
    ll suml[n + 1], sumr[n + 1];
    rep(i, n + 1)
    {
        suml[i] = 0; //**********<=こっちがわ
        sumr[i] = 0; //=>**********こっちがわ
    }

    rep(i, n)
    {
        cin >> l[i];
    }
    suml[0] = 0;
    rep(i, 0, n)
    {
        suml[i + 1] = -suml[i] + l[i];
    }

    sumr[n] = 0;
    for (int i = n; i >= 0; i--)
    {
        sumr[i - 1] = -sumr[i] - l[i - 1];
    }
    rep(i, n)
    {
        cout << suml[i] + l[i] + sumr[i + 1] << " ";
    }
    cout << endl;

    return 0;
}
