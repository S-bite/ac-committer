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
    int l;
    cin >> n >> l;
    vector<int> a(n, 0), b(n + 1, 0);
    b[0] = 0;
    a[0] = l;
    rep(i, n)
    {
        a[i] = l + i;
        b[i + 1] = b[i] + a[i];
    }
    int ans = -1;
    int best = (1 << 30);
    rep(i, n)
    {
        if (abs(a[i]) < best)
        {
            ans = i;
            best = abs(a[i]);
        }
    }
    cout << b[n] - a[ans] << endl;
    return 0;
}
