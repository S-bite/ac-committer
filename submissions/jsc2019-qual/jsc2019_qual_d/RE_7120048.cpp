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
ll MOD = 1000000007ll;
using namespace std;
vector<vector<int>> g;

void gen(vector<int> &v, int nowcol)
{
    sort(ALL(v));

    rep(i, v.size() / 2)
    {
        rep(j, v.size() / 2, v.size())
        {
            g[v[i]][v[j]] = nowcol;
        }
    }
    nowcol++;
    if (v.size() / 2 <= 2)
    {
        rep(i, v.size() / 2)
        {
            rep(j, i + 1, v.size())
            {
                g[v[i]][v[j]] = nowcol;
            }
        }
    }
    else
    {
        vector<int> v2;
        rep(i, v.size() / 2)
        {
            v2.push_back(v[i]);
        }
        gen(v, nowcol);
    }
    if (v.size() - (v.size() / 2) <= 2)
    {
        rep(i, v.size() / 2)
        {
            rep(j, i + 1, v.size())
            {
                g[v[i]][v[j]] = nowcol;
                g[v[j]][v[i]] = nowcol;
            }
        }
    }
    else
    {
        vector<int> v2;
        rep(i, v.size() / 2, v.size())
        {
            v2.push_back(v[i]);
        }
        gen(v, nowcol);
    }
}

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    vector<int> v;
    g = vector<vector<int>>(n, vector<int>(n, 0));
    rep(i, n) v.push_back(i);
    gen(v, 0);
    rep(i, n)
    {
        rep(j, i + 1, n)
        {
            cout << g[i][j] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
