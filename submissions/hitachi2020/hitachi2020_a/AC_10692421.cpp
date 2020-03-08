#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;
map<int, int> ans;
map<int, vector<int>> g;
int main()
{
    string s;
    cin >> s;
    if (s.size() % 2 == 1)
    {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < s.size(); i += 2)
    {
        if (s[i] != 'h' || s[i + 1] != 'i')
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}