#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

bool is_ok(vector<int> &v, vector<int> &op)
{
    int ans = v[0];
    rep(i, 3)
    {
        if (op[i] == 0)
        {
            ans += v[i + 1];
        }
        else
        {
            ans -= v[i + 1];
        }
    }
    return ans == 7;
}

int main(int argc, char const *argv[])
{
    vector<int> v(4);
    string s;
    cin >> s;
    rep(i, 4)
    {
        v[i] = s[i] - '0';
    }
    vector<int> op(3);
    rep(i, 8)
    {
        op[0] = (i >> 0) & 1;
        op[1] = (i >> 1) & 1;
        op[2] = (i >> 2) & 1;
        if (is_ok(v, op))
        {
            cout << v[0];
            rep(j, 3)
            {
                cout << (op[j] == 0 ? '+' : '-');
                cout << v[j + 1];
            }
            cout << "=7" << endl;
            return 0;
        }
    }
    return 0;
}