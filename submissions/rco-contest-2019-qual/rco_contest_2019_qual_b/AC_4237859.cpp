#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define fir first
#define sec second
#define N 50
#define M 2500
using namespace std;
ll eval(int g[N][N], int sx, int sy, int num)
{
    if (g[sy][sx] != num)
        return 0;

    ll ret = num;
    g[sy][sx] = -1;
    if (sx > 0)
    {
        ret += eval(g, sx - 1, sy, num);
    }
    if (sx < N - 1)
    {
        ret += eval(g, sx + 1, sy, num);
    }
    if (sy > 0)
    {
        ret += eval(g, sx, sy - 1, num);
    }
    if (sy < N - 1)
    {
        ret += eval(g, sx, sy + 1, num);
    }

    return ret;
}
int main()
{
    random_device rnd;
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
        ll score = 0;
        string op = "";

        rep(i, 100)
        {
            int c = rnd() % (n * n);
            int sx = c % n;
            int sy = c / n;
            int x = sx, y = sy;
            rep(j, m / 100 - 1)
            {

                // cout << g[y][x] << endl;
                if (g[y][x] != 9 && g[y][x] != -1)
                {

                    op = op + "1 " + to_string(y) + " " + to_string(x) + "\n";
                    g[y][x]++;
                }
                else
                {
                    if (x == n - 1)
                    {
                        y++;
                    }
                    else if (y == n - 1)
                    {
                        x++;
                    }
                    else
                    {
                        if (g[y][x + 1] > g[y + 1][x])
                        {
                            x++;
                        }
                        else
                            y++;
                    }
                }
                if (x == n - 1 && y == n - 1)
                    break;
            }
            op = op + "2 " + to_string(sy) + " " + to_string(sx) + "\n";
            // cout << op << endl;
            score += eval(g, sx, sy, 9);
        }
        if (score > bestscore)
        {
            bestop = op;
            bestscore = score;
        }
        thread = 7; //random() % 8;
        //cout << "fin" << endl;
    }
    cout << bestop << endl;
    //cout << bestscore << endl;

    return 0;
}
