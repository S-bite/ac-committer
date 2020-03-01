#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
void update(vector<vector<int>> &v, vector<vector<int>> &m, int n)
{
    rep(i, 3) rep(j, 3)
    {
        if (v[i][j] == n)
        {
            m[i][j] = 1;
        }
    }
}

bool check(vector<vector<int>> &m)
{
    bool ret = false;
    bool cur = true;
    rep(i, 3)
    {
        rep(j, 3) cerr << m[i][j];
        cerr << endl;
    }
    rep(i, 3)
    {
        cur = true;
        rep(j, 3)
        {
            cur &= (m[i][j] == 1 ? true : false);
        }
        ret |= cur;
    }
    rep(i, 3)
    {
        cur = true;
        rep(j, 3)
        {
            cur &= (m[j][i] == 1 ? true : false);
        }
        ret |= cur;
    }
    cur = true;
    rep(j, 3)
    {
        cur &= (m[j][j] == 1 ? true : false);
    }
    ret |= cur;
    cur = true;
    rep(j, 3)
    {
        cur &= (m[j][2 - j] == 1 ? true : false);
    }
    ret |= cur;
    return ret;
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> v(3, vector<int>(3, 0));
    auto m = v;
    rep(i, 3) rep(j, 3) cin >> v[i][j];
    int n;
    cin >> n;
    rep(i, n)
    {
        int t;
        cin >> t;
        update(v, m, t);
    }
    if (check(m))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
