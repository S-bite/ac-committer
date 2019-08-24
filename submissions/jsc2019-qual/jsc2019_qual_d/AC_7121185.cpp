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

void gen(int s, int e, int nowcol)
{
   // cerr << s << " " << e << endl;
    int med = (e + s) / 2;
    rep(i, s, med)
    {
        rep(j, med, e)
        {
            g[i][j] = nowcol;
            g[j][i] = nowcol;
        }
    }
    nowcol++;
    if (med - s <= 2)
    {
        rep(i, s, med)
        {
            rep(j, i + 1, med)
            {
                g[i][j] = nowcol;
                g[j][i] = nowcol;
            }
        }
    }
    else
    {
        gen(s, med, nowcol);
    }

    if (e - med <= 2)
    {
        rep(i, med, e)
        {
            rep(j, i + 1, e)
            {
                g[i][j] = nowcol;
                g[j][i] = nowcol;
            }
        }
    }
    else
    {
        gen(med, e, nowcol);
    }
}

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    g = vector<vector<int>>(n, vector<int>(n, 0));
    gen(0, n, 0);
    cerr << 0 << endl;
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
