#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define fir first
#define sec second
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int g[n][n];
    rep(i, n) rep(j, n) cin >> g[i][j];
    int c = 0;
    rep(i, m - 1)
    {
        int x = c % n;
        int y = c / n;
        if (g[y][x] != 9)
        {
            cout << 1 << " " << y << " " << x << endl;
            g[y][x]++;
        }
        else
            c++;
        if (c >= n * n)
            break;
    }
    cout << "2 0 0" << endl;
    return 0;
}