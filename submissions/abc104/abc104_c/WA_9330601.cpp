#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

pair<ll, ll> calc1(ll d, ll g, vector<ll> &p, vector<ll> &c, vector<bool> &pick)
{
    ll num = 0;
    ll remain = g;
    rep(i, d)
    {
        if (pick[i] == true)
        {
            num += p[i];
            remain -= p[i] * (i + 1) * 100 + c[i];
        }
    }
    return {num, remain};
}

int calc2(ll d, ll remain, vector<ll> &p, vector<ll> &c, vector<bool> &pick)
{
    ll IINF = (1 << 30);
    ll ret = IINF;
    rep(i, d)
    {
        if (pick[i] == false)
        {
            if ((p[i] - 1) * (i + 1) * 100 < remain)
            {
                continue;
            }
            ll cur = (remain + (i + 1) * 100 - 1) / ((i + 1) * 100);
            ret = min(ret, cur);
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    ll d, g;
    ll pnum = 0;
    cin >> d >> g;
    vector<ll> p(d), c(d);
    rep(i, d)
    {
        cin >> p[i] >> c[i];
        pnum += p[i];
    }
    vector<ll> score(d + 1);
    ll ans = (1 << 30);
    rep(i, (1 << d))
    {
        vector<bool> pick;
        rep(j, d)
        {
            pick.push_back((((i >> j) & 1) == 1) ? true : false);
            //    cerr << pick.back() << " ";
        }
        //cerr << endl;
        auto ret = calc1(d, g, p, c, pick);
        //cerr << ret.first << " " << ret.second << endl
        //    << endl;
        if (ret.second < 0)
            ans = min(ans, ret.first);
        else
            ans = min(ans, ret.first + calc2(d, ret.second, p, c, pick));
    }

    cout << ans << endl;
    return 0;
}
