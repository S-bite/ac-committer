#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define fir first
#define sec second
#define N 50
#define M 2500
using namespace std;
ll eval(int g[N][N], int sx, int sy)
{
    if (g[sy][sx] != 9)
        return 0;

    ll ret = 9;
    g[sy][sx] = -1;
    if (sx > 0)
    {
        ret += eval(g, sx - 1, sy);
    }
    if (sx < N - 1)
    {
        ret += eval(g, sx + 1, sy);
    }
    if (sy > 0)
    {
        ret += eval(g, sx, sy - 1);
    }
    if (sy < N - 1)
    {
        ret += eval(g, sx, sy + 1);
    }

    return ret;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int g[N][N], _g[N][N];
    rep(i, n) rep(j, n) cin >> g[i][j];
    rep(i, n) rep(j, n) _g[i][j] = g[i][j];
    ll bestscore = -1;
    string bestop = "";
    clock_t start = clock();
    int thread = 0;

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
            if (g[y][x] != 9 && g[y][x] >= thread)
            {

                op = op + "1 " + to_string(y) + " " + to_string(x) + "\n";
                g[y][x]++;
            }
            else
            {
                c++;
            }
            if (c >= n * n)
                break;
        }
        op = op + "2 " + to_string(sy) + " " + to_string(sx) + "\n";
        // cout << op << endl;
        score = eval(g, sx, sy);
        if (score > bestscore)
        {
            bestop = op;
            bestscore = score;
        }
        thread = random() % 8;
        //cout << "fin" << endl;
    }
    cout << bestop << endl;
    //cout << bestscore << endl;

    return 0;
}
