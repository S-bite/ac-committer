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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> p(n, {0, 0});
    rep(i, n)
    {
        cin >> p[i].second >> p[i].first;
    }

    sort(ALL(p));
    multiset<ll> s;
    if (p[0].first < p[0].second)
    {
        cout << "No" << endl;
        return 0;
    }

    s.insert(p[0].first - p[0].second);
    ll last = *s.begin();
    rep(i, 1, n)
    {
        ll dur = p[i].first;
        ll cost = p[i].second;
        ll newval = last + (dur - p[i - 1].first);
        s.erase(last);
        s.insert(newval);
        auto itr = s.lower_bound(cost);
        if (itr == s.end())
        {
            cout << "No" << endl;
            return 0;
        }
        ll val = *itr;
        itr++;

        s.erase(val);
        s.insert(val - cost);
        if (val == newval)
        {
            last = val - cost;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
