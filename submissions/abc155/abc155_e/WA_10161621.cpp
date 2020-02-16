#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const ll INF = 1ll << 60;

int main()
{
    string s;
    cin >> s;
    vector<ll> sum(s.size() + 1, 0);
    vector<ll> ten(s.size() + 1, 0);
    vector<ll> nine(s.size() + 1, 0);
    vector<ll> best(s.size() + 1, 0);

    int c = 10;
    //best[s.size()] = min(s.back() - '0', c - (s.back() - '0'));
    //if (s.back() != '0')
    //   c = 9;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        /*
        sum[i] = sum[i] + ((s[i] - '0'));
        ten[i] = ten[i] + min(10 - (s[i] - '0'), s[i] - '0');
        nine[i = nine[i] + min(9 - (s[i] - '0'), s[i] - '0');
        */
        if (c == 10)
        {
            if (s[i] - '0' < c - (s[i] - '0'))
            {
                best[i] = best[i + 1] + (s[i] - '0');
            }
            else
            {
                best[i] = best[i + 1] + (c - (s[i] - '0'));
                c = 9;
            }
        }
        else
        {
            if (9 - (s[i] - '0') < 1 + (s[i] - '0'))
            {
                best[i] = best[i + 1] + 9 - (s[i] - '0');
            }
            else
            {
                best[i] = best[i + 1] + 1 + (s[i] - '0');
                c = 10;
            }
        }
    }

    ll ans = INF;
    // = sum[s.size()];
    cerr << best[0] << endl;
    ans = min(ans, 1 + best[0]);
    ll cur = 0;
    rep(i, s.size())
    {
        cur += min(10 - (s[i] - '0'), (s[i] - '0'));

        ll paynow = cur + 1;
        paynow += best[i + 1];
        ans = min(ans, paynow);
    }
    ans = min(ans, cur);
    cout << ans << endl;
    return 0;
}