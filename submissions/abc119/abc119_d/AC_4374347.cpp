#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ll long long
#define ALL(x) x.begin(), x.end()
#define fir first
#define sec second
#define INF (1ll << 60)
using namespace std;

int main()
{
    ll a, b, q;
    cin >> a >> b >> q;
    vector<ll> s, t;
    rep(i, a)
    {
        ll T;
        cin >> T;
        s.push_back(T);
    }
    rep(i, b)
    {
        ll T;
        cin >> T;
        t.push_back(T);
    }
    rep(i, q)
    {
        ll x;
        cin >> x;
        ll sl, sr, tl, tr;
        auto itr = lower_bound(ALL(s), x);
        if (itr == s.end())
        {
            sr = INF;
            sl = *(itr - 1);
        }
        else
        {
            sr = *itr;
            if (itr == s.begin())
            {
                sl = -INF;
            }
            else
                sl = *(itr - 1);
        }

        itr = lower_bound(ALL(t), x);
        if (itr == t.end())
        {
            tr = INF;
            tl = *(itr - 1);
        }
        else
        {
            tr = *itr;
            if (itr == t.begin())
            {
                tl = -INF;
            }
            else
                tl = *(itr - 1);
        }
        //cout << sl << "," << sr << "," << tl << "," << tr << endl;
        ll ans = min({
            llabs(x - sr) + llabs(sr - tr),
            llabs(x - sr) + llabs(sr - tl),

            llabs(x - sl) + llabs(sl - tr),
            llabs(x - sl) + llabs(sl - tl),

            llabs(x - tr) + llabs(tr - sr),
            llabs(x - tr) + llabs(tr - sl),

            llabs(x - tl) + llabs(tl - sr),
            llabs(x - tl) + llabs(tl - sl),
        });
        cout << ans << endl;
    }

    return 0;
}