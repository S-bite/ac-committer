#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#ifdef DEBUG
#define line() cout << "[" << __LINE__ << "] ";
#define dump(i) cout << #i ": " << i << " ";
#define dumpl(i) cout << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
#define MOD 1000000007ll
using namespace std;

int main(int argc, char const *argv[])
{

    ll n;
    cin >> n;
    string s;
    cin >> s;
    map<int, ll> mp;
    rep(i, n)
    {
        mp[s[i]]++;
    }
    ll ans = 1;
    rep(i, 'a', 'z' + 1)
    {
        ans *= mp[i] + 1;
        ans %= MOD;
    }
    ans--;
    ans %= MOD;

    cout << ans << endl;
    return 0;
}
