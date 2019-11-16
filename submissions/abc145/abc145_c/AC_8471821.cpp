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
lld sum = 0;
int n;

void dfs(vector<ll> &x, vector<ll> &y, vector<bool> &visited, int curid, lld curdist)
{
    bool done = true;
    rep(i, n)
    {
        done &= visited[i];
    }
    if (done)
    {
        sum += curdist;
        return;
    }
    rep(i, n)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            lld newdist = curdist + sqrt((x[i] - x[curid]) * (x[i] - x[curid]) + (y[i] - y[curid]) * (y[i] - y[curid]));
            dfs(x, y, visited, i, newdist);
            visited[i] = false;
        }
    }
}
int main(int argc, char const *argv[])
{
    cin >> n;
    vector<ll> x(n), y(n);
    vector<bool> visited(n, false);
    rep(i, n) cin >> x[i] >> y[i];
    rep(i, n)
    {
        visited[i] = true;
        dfs(x, y, visited, i, 0.0);
        visited[i] = false;
    }
    int m = 1;
    rep(i, 1, n + 1)
    {
        m *= i;
    }
    printf("%0.10Lf\n", sum / (lld)m);
    return 0;
}
