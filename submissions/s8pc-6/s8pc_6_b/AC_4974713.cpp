#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
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

int main()
{
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll> a, b;
    rep(i, n)
    {
        ll s, e;
        cin >> s >> e;
        sum += e - s;
        a.push_back(s);
        b.push_back(e);
    }
    sort(ALL(a));
    sort(ALL(b));
    ll enter, exit;
    if (n % 2 == 0)
    {
        enter = (a[n / 2] + a[n / 2 - 1]) / 2;
        exit = (b[n / 2] + b[n / 2 - 1]) / 2;
    }
    else
    {
        enter = a[n / 2];
        exit = b[n / 2];
    }
    rep(i, n)
    {
        sum += abs(a[i] - enter);
        sum += abs(b[i] - exit);
    }
    cout << sum << endl;
    return 0;
}