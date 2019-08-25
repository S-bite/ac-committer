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

typedef pair<int, int> PII;
int main(int argc, char const *argv[])
{
    string s, t;
    cin >> s >> t;
    ll x[s.size() + 1];
    ll y[t.size() + 1];
    x[0] = 0;
    rep(i, s.size())
    {
        x[i + 1] = x[i] + (s[i] == 'A' ? 1 : 2);
        //cerr << x[i + 1] << endl;
    }

    y[0] = 0;
    rep(i, t.size())
    {
        y[i + 1] = y[i] + (t[i] == 'A' ? 1 : 2);
    }
    int q;
    cin >> q;
    rep(i, q)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        //cerr << x[b] - x[a - 1] << "," << y[d] - y[c - 1] << endl;
        if ((x[b] - x[a - 1]) % 3 == (y[d] - y[c - 1]) % 3)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
