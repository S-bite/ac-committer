#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
int main(int argc, char const *argv[])
{
    int n, q;
    cin >> n >> q;
    vector<int> flip(n, 0);
    rep(i, q)
    {
        int l, r;
        cin >> l >> r;
        flip[l - 1] ^= 1;
        flip[r] ^= 1;
    }
    int cur = 0;
    rep(i, n)
    {
        cur ^= flip[i];
        cout << cur;
    }
    cout << endl;
    return 0;
}
