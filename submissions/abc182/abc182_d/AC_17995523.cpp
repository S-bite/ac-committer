#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const double EPS = 1e-3;
const double PI = 3.1415926535897932384626433832795028841971;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int main()
{
    priority_queue<ll> pque;
    pque.push(0);
    ll cur = 0;
    ll diff = 0;
    ll dmax = 0;
    int n;
    cin >> n;
    rep(i, n)
    {
        int t;
        cin >> t;
        diff += t;
        dmax = max(dmax, diff);
        pque.push(cur + dmax);
        cur += diff;
        //cerr << cur << endl;
        pque.push(cur);
    }
    cout << pque.top() << endl;
    return 0;
}