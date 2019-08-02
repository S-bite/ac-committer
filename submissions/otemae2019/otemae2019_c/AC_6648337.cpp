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
#define MOD 1000000007ll
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    map<int, int> mp;
    map<int, int> c;

    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n)
    {
        cin >> b[i];
        mp[b[i]]++;
    }
    int now = mp[a[0]];
    cout << now << endl;
    c[a[0]]++;
    rep(i, 1, n)
    {
        c[a[i]]++;
        now = min(now, mp[a[i]] / c[a[i]]);
        cout << now << endl;
    }

    return 0;
}

//0 1 2 3 4 1 1 1