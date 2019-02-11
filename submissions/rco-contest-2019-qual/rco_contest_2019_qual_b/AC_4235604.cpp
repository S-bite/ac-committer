#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define fir first
#define sec second
#define N
#define M
#define ALL(x) x.begin(), x, end()
using namespace std;
struct Crop
{
    int x;
    int y;
    int a;
};
bool comp(const Crop &lh, const Crop &rh)
{
    // 文字列lhの長さが文字列rhより短かったらtrueを返す
    return lh.a > rh.a;
}
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
    while ((double)(clock() - start) / CLOCKS_PER_SEC * 1000.0 < 1800.0)
    {
        bool u[n][n];
        rep(i, n) rep(j, n) g[i][j] = _g[i][j];
        rep(i, n) rep(j, n) u[i][j] = false;

        int c = 0;
        //random() % (n * n);
        int sx = c % n;
        int sy = c / n;
        u[sy][sx] = true;
        ll score = 0;
        ll rm = m;
        vector<Crop> v;
        v.push_back(Crop{sx, sy, g[sy][sx]});
        string op = "";
        rep(i, m - 1)
        {
            if (g[sy][sx] != 9)
            {
                op = op + "1 " + to_string(sy) + " " + to_string(sx) + "\n";
                g[sy][sx]++;
            }
            else
            {
                vector<Crop> t;
                for (auto itr = v.begin(); itr != v.end(); itr++)
                {
                    int ix = itr->x;
                    int iy = itr->y;
                    if (ix > 0 && u[iy][ix - 1] == false)
                    {
                        t.push_back(Crop{ix - 1, iy, g[iy][ix - 1]});
                    }
                    if (ix < n - 1 && u[iy][ix + 1] == false)
                    {
                        t.push_back(Crop{ix + 1, iy, g[iy][ix + 1]});
                    }
                    if (iy > 0 && u[iy - 1][ix] == false)
                    {
                        t.push_back(Crop{ix, iy - 1, g[iy - 1][ix]});
                    }
                    if (iy < n - 1 && u[iy + 1][ix] == false)
                    {
                        t.push_back(Crop{ix, iy + 1, g[iy + 1][ix]});
                    }
                }
                sort(t.begin(), t.end(), comp);
                // cout << v.size() << "-------------------------" << endl;
                //rep(j, n)
                // {
                //    rep(k, n) cout << u[j][k];
                //   cout << endl;
                //}

                for (auto itr = t.begin(); itr != t.end(); itr++)
                {
                    if (itr->a == 9 && u[itr->y][itr->x] == false)
                    {
                        score += 9;
                        v.push_back(*itr);
                        u[itr->y][itr->x] = true;
                    }
                    else
                    {
                        op = op + "1 " + to_string(itr->y) + " " + to_string(itr->x) + "\n";
                        g[itr->y][itr->x]++;
                        break;
                    }
                }
            }
        }
        op = op + "2 " + to_string(sy) + " " + to_string(sx) + "\n";
        // cout << op << endl;
        //cout << "fin" << endl;
        if (score > bestscore)
        {
            bestop = op;
            bestscore = score;
        }
    }
    cout << bestop << endl;
    return 0;
}