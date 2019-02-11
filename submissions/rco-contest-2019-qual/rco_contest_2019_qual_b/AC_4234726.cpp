#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define fir first
#define sec second
#define N
#define M
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int g[n][n], _g[n][n];
    rep(i, n) rep(j, n) cin >> g[i][j];
    rep(i, n) rep(j, n) _g[i][j] = g[i][j];
    ll bestscore = -1;
    string bestop = "";
    clock_t start = clock();
    while ((double)(clock() - start) / CLOCKS_PER_SEC * 1000.0 < 1900.0)
    {
        rep(i, n) rep(j, n) g[i][j] = _g[i][j];
        int c = random() % ((n * n * 3) / 4);
        ll score = 0;
        string op = "";
        int sx = c % n;
        int sy = c / n;
        rep(i, m - 1)
        {
            int x = c % n;
            int y = c / n;
            // cout << g[y][x] << endl;
            if (g[y][x] != 9)
            {

                op = op + "1 " + to_string(y) + " " + to_string(x) + "\n";
                g[y][x]++;
            }
            else
            {
                c++;
                score += 9;
            }
            if (c >= n * n)
                break;
        }
        op = op + "2 " + to_string(sy) + " " + to_string(sx) + "\n";
        // cout << op << endl;
        if (score > bestscore)
        {
            bestop = op;
            bestscore = score;
        }
    }
    cout << bestop << endl;
    return 0;
}