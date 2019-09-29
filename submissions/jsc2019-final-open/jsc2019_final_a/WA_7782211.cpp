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
    map<int, pair<int, int>> ap, bp;
    rep(i, 1010101)
    {
        ap[i] = {-1, -1};
        bp[i] = {-1, -1};
    }
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

            if (ap[b[be] - b[bs]].first != -1)
            {
                int s = a[ap[b[be] - b[bs]].first];
                int e = a[ap[b[be] - b[bs]].second];
                cout << mpa[e] << " " << mpb[b[bs]] << " " << mpa[s] << " " << mpb[b[be]] << endl;

                return 0;
            }

            if (bp[a[ae] - a[as]].first != -1)
            {
                int s = b[bp[a[ae] - a[as]].first];
                int e = b[bp[a[ae] - a[as]].second];
                cout << mpa[a[ae]] << " " << mpb[s] << " " << mpa[a[as]] << " " << mpb[e] << endl;

                return 0;
            }
            bp[b[be] - b[bs]] = {bs, be};
            ap[a[ae] - a[as]] = {as, ae};
        }
    }
    cout << -1 << endl;
    return 0;
}