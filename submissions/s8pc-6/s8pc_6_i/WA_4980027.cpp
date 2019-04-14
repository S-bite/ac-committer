#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
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
class UF
{
private:
public:
    UF *root;
    int value;
    UF(int n = 0)
    {
        root = this;
        value = n;
    }
    void showInfo(void)
    {
        cout << "rootNode:" << root << ",value:" << value << endl;
    }
};

void connectNode(UF *a, UF *b)
{
    while (b->root != b)
        b = b->root;
    while (a->root != a)
        a = a->root;

    if (a > b)
    {
        a->root = b;
    }
    if (a < b)
    {
        b->root = a;
    }
    return;
}
bool hasSameRoot(UF *a, UF *b)
{
    UF *pa = a;
    UF *pb = b;
    while (a->root != a)
        a = a->root;
    while (b->root != b)
        b = b->root;
    pa->root = a;
    pb->root = b;

    return a == b;
}

int main(int argc, char const *argv[])
{
    int h, w;
    cin >> h >> w;

    UF g[h][w];
    vector<vector<bool>> b(h, vector<bool>(w, false));
    rep(i, h) rep(j, w) cin >> g[i][j].value;
    int st = -1;
    int best = 0;
    b[1][0] = true;
    int norma = 4;

    bool cng = true;
    while (cng)
    {
        cng = false;
        rep(i, h) rep(j, w)
        {
            //  cerr << i << "," << j << endl;
            int x = j, y = i;
            if (b[i][j] == true || !(
                                       ((x == 0) || (x == w - 1) || !hasSameRoot(&g[y][x + 1], &g[y][x - 1])) && ((x == 0) || (y == h - 1) || !hasSameRoot(&g[y + 1][x], &g[y][x - 1])) && ((x == 0) || (y == 0) || !hasSameRoot(&g[y - 1][x], &g[y][x - 1])) && ((x == w - 1) || (y == 0) || !hasSameRoot(&g[y - 1][x], &g[y][x + 1])) && ((x == w - 1) || (y == h - 1) || !hasSameRoot(&g[y + 1][x], &g[y][x + 1]))))
            {
                //  cerr << "false" << endl;
                continue;
            }
            // cerr << "right" << endl;

            if (j + 1 < w && g[i][j].value > norma && b[i][j + 1] == true)
            {
                connectNode(&g[i][j], &g[i][j + 1]);
                b[i][j] = true;
                cng = true;
                break;
            }
            //  cerr << "left" << endl;

            if (j - 1 >= 0 && g[i][j].value > norma && b[i][j - 1] == true)
            {
                connectNode(&g[i][j], &g[i][j - 1]);
                b[i][j] = true;
                cng = true;
                break;
            }
            //  cerr << "up" << endl;

            if (i - 1 >= 0 && g[i][j].value > norma && b[i - 1][j] == true)
            {
                connectNode(&g[i][j], &g[i - 1][j]);
                b[i][j] = true;
                cng = true;
                break;
            }
            // cerr << "down" << endl;

            if (i + 1 < h && g[i][j].value > norma && b[i + 1][j] == true)
            {
                connectNode(&g[i][j], &g[i + 1][j]);
                b[i][j] = true;
                cng = true;
                break;
            }
        }
        //cerr << "w" << endl;
    }
    cng = true;

    while (false)
    {
        cng = false;
        // union others
        rep(i, h) rep(j, w)
        {
            // cerr << i << "," << j << endl;
            int x = j, y = i;
            if (
                b[i][j] == true || !(
                                       ((x == 0) || (x == w - 1) || !hasSameRoot(&g[y][x + 1], &g[y][x - 1])) &&
                                       ((x == 0) || (y == h - 1) || !hasSameRoot(&g[y + 1][x], &g[y][x - 1])) &&
                                       ((x == 0) || (y == 0) || !hasSameRoot(&g[y - 1][x], &g[y][x - 1])) &&
                                       ((x == w - 1) || (y == 0) || !hasSameRoot(&g[y - 1][x], &g[y][x + 1])) &&
                                       ((x == w - 1) || (y == h - 1) || !hasSameRoot(&g[y + 1][x], &g[y][x + 1])) &&
                                       ((y == 0) || (y == h - 1) || !hasSameRoot(&g[y + 1][x], &g[y - 1][x]))))

            {
                //  cerr << "false" << endl;
                continue;
            }
            //   cerr << "right" << endl;
            if (j + 1 < w && b[i][j + 1] == true)
            {
                connectNode(&g[i][j], &g[i][j + 1]);
                b[i][j] = true;
                cng = true;
                break;
            }
            // cerr << "left" << endl;

            if (j - 1 >= 0 && b[i][j - 1] == true)
            {
                connectNode(&g[i][j], &g[i][j - 1]);
                b[i][j] = true;
                cng = true;
                break;
            }
            //  cerr << "up" << endl;

            if (i - 1 >= 0 && b[i - 1][j] == true)
            {
                connectNode(&g[i][j], &g[i - 1][j]);
                b[i][j] = true;
                cng = true;
                break;
            }

            // cerr << "down" << endl;

            if (i + 1 < h && b[i + 1][j] == true)
            {
                connectNode(&g[i][j], &g[i + 1][j]);
                b[i][j] = true;
                cng = true;
                break;
            }
        }
        //   cout << cng << endl;
    }
    rep(i, h)
    {
        rep(j, w)
        {
            if (b[i][j])
                cout << "#";
            else
                cout << ".";
        }
        cout << endl;
    }
    return 0;
}
