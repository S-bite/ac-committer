#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
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
using namespace std;

int main(int argc, char const *argv[])
{
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;
    int a[n];
    rep(i, n) a[i] = 0;
    rep(i, 1, n)
    {
        a[i] = a[i - 1];
        if (s[i] == 'C' && s[i - 1] == 'A')
        {
            a[i]++;
        }
    }
    rep(i, q)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << a[r] - a[l] << endl;
    }
    return 0;
}
