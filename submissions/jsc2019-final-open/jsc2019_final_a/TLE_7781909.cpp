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

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    map<int, int> mpa, mpb;
    rep(i, n)
    {
        cin >> a[i];
        mpa[a[i]] = i;
    }
    rep(i, m)
    {
        cin >> b[i];
        mpb[b[i]] = i;
    }
    sort(a, a + n);
    sort(b, b + m);

    rep(i, n) cerr << a[i] << " ";
    cerr << endl;
    int as, ae, bs, be;
    rep(as, n) rep(bs, m)
    {
        rep(ae, as + 1, n) rep(be, bs + 1, m)
        {

            if (a[ae] - a[as] == b[be] - b[bs])
            {
                cout << mpa[a[ae]] << " " << mpb[b[bs]] << " " << mpa[a[as]] << " " << mpb[b[be]] << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}