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
    string s;
    cin >> s;
    ll k;
    cin >> k;
    rep(i, s.size())
    {
        ll acost = 26 - s[i] + 'a';
        cerr << acost << endl;
        if (acost <= k)
        {
            k -= acost;
            s[i] = 'a';
        }
    }
    s.back()= (s.back() - 'a' + (k%26)) % 26 + 'a';
    cout << s << endl;
    return 0;
}
