#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = (1'000'000'000 + 7);

bool is_ok(string s)
{
    int n = s.size();
    rep(i, n / 2)
    {
        if (s[i] != s[n - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    cerr << s << endl;
    cerr << s.substr(0, (n - 1) / 2) << endl;
    cerr << s.substr((n + 1) / 2, n - (n + 1) / 2 + 1) << endl;
    if (is_ok(s) && is_ok(s.substr(0, (n - 1) / 2))

        && is_ok(s.substr((n + 1) / 2, n - (n + 1) / 2 + 1)))

    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}