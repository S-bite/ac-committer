#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <chrono>
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

int binarySeach(vector<int> &v, int n, int t, bool eq)
{
    int r = v.size();
    int l = -1;
    while (l + 1 != r)
    {
        int med = (r + l) / 2;
        int now = v[med];
        if (now > t || (eq && now == t))
        {
            r = med;
        }
        else
            l = med;
    }
    return r;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a, b, c;
    rep(i, n)
    {
        int _;
        cin >> _;
        a.push_back(_);
    }
    rep(i, n)
    {
        int _;
        cin >> _;
        b.push_back(_);
    }
    rep(i, n)
    {
        int _;
        cin >> _;
        c.push_back(_);
    }

    sort(ALL(a));
    sort(ALL(b));
    sort(ALL(c));

    ll ans = 0;
    rep(i, n)
    {

        ll anum = binarySeach(a, n, b[i], true);
        ll cnum = n - binarySeach(c, n, b[i], false);
        // dumpl(anum);
        // dumpl(cnum);
        ans += anum * cnum;
    }
    cout << ans << endl;
    return 0;
}
