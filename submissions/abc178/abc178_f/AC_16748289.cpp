#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
random_device rnd;
mt19937 mt(rnd());
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;

int check(vector<PII> &x, vector<PII> &y, VI &order)
{
    int idxx = 0;
    int curx, cury;
    curx = x[0].first;
    rep(i, y.size())
    {
        int idxy = order[i];
        cury = y[idxy].first;
        while (cury > 0)
        {
            if (x[idxx].second == y[idxy].second)
            {
                return i;
            }
            if (curx > cury)
            {
                curx -= cury;
                cury = 0;
            }
            else
            {
                cury -= curx;
                curx = 0;
            }
            if (curx == 0)
            {
                idxx++;
                curx = x[idxx].first;
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    VI a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    int preva = -1, prevb = -1;
    int j = 0;
    rep(i, n)
    {
        if (preva != a[i] || prevb != b[i])
            j = 0;
        if (a[i] == b[i])
        {
            prevb = b[i];
            for (; j < n; j++)
            {
                if (b[i] != a[j] && b[j] != a[i])
                {
                    swap(b[i], b[j]);
                    break;
                }
            }
            if (a[i] == b[i])
            {
                cout << "No" << endl;
                return 0;
            }
        }
        preva = a[i];
    }
    cout << "Yes" << endl;
    rep(i, n)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}