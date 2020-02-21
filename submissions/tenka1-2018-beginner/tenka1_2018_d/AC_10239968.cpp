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
void print(int n, int k)
{
    map<int, int> mp;
    cout << k << endl;
    vector<vector<int>> g(k, vector<int>(k, -1));
    int cur = 0;
    rep(i, k) rep(j, i + 1, k)
    {
        if (g[i][j] == -1)
        {
            g[i][j] = cur;
            g[j][i] = cur;
            cur++;
        }
    }
    rep(i, k)
    {
        int cur = 0;
        cout << k - 1 << " ";
        rep(j, k)
        {
            if (g[i][j] != -1)
            {
                cout << g[i][j] + 1 << " ";
            }
        }
        cout << endl;
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int k = 2;
    while (k * (k - 1) / 2 <= n)
    {
        if (k * (k - 1) / 2 == n)
        {
            cout << "Yes" << endl;
            print(n, k);
            return 0;
        }
        k++;
    }
    cout << "No" << endl;
    return 0;
}
