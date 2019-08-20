#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#define MOD (ll)(1e9 + 7)
using namespace std;
int main()
{
    int n;
    cin >> n;
    priority_queue<int> l;
    deque<int> r;
    ll lsum = 0, rsum = 0;
    vector<int> a(3 * n, 0);
    rep(i, 3 * n) cin >> a[i];
    rep(i, n)
    {

        l.push(-a[i]);
        lsum += a[i];
        r.push_back(a[n + i]);
        rsum += a[n + i];
    }
    rep(i, 2 * n, 3 * n)
    {
        //cerr << lsum << "," << rsum << "," << a[i] << endl;
        if ((l.top() + r.front()) - (-r.front() + a[i]) > 0)
        {
            lsum = lsum + l.top() + r.front();
            rsum = rsum - r.front() + a[i];
            l.pop();
            l.push(-r.front());
            r.pop_front();
            r.push_back(a[i]);
        }
    }
    cout << lsum - rsum << endl;
    return 0;
}