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
#define MOD (ll)(1e9 + 7)
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
        value = 1;
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
int main()
{
    int h, w;
    cin >> h >> w;
    char g[h][w];
    int x[h][w], y[h][w];
    rep(i, h) rep(j, w)
    {
        x[i][j] = 0;
        y[i][j] = 0;
        cin >> g[i][j];
    }
    rep(i, h)
    {
        int st = 0;
        int num = 0;
        rep(j, w + 1)
        {
            if (g[i][j] == '.' && j != w)
            {
                num++;
            }
            else
            {
                rep(k, st, j)
                {
                    x[i][k] = num;
                }
                num = 0;
                st = j + 1;
            }
        }
    }
    rep(j, w)
    {
        int st = 0;
        int num = 0;
        rep(i, h + 1)
        {
            if (g[i][j] == '.' && i != h)
            {
                num++;
            }
            else
            {
                rep(k, st, i)
                {
                    y[k][j] = num;
                }
                num = 0;
                st = i + 1;
            }
        }
    }

    int ans = -1;
    rep(i, h) rep(j, w)
    {
        ans = max(ans, x[i][j] + y[i][j] - 1);
    }
    cout << ans << endl;
    return 0;
}