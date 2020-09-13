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
    vector<PII> x, y;
    x.push_back({1, a[0]});
    rep(i, 1, n)
    {
        if (x.back().second == a[i])
        {
            x.back().first++;
        }
        else
        {
            x.push_back({1, a[i]});
        }
    }

    y.push_back({1, b[0]});
    rep(i, 1, n)
    {
        if (y.back().second == b[i])
        {
            y.back().first++;
        }
        else
        {
            y.push_back({1, b[i]});
        }
    }

    VI order(y.size());

    rep(i, y.size())
    {
        order[i] = i;
    }
    shuffle(ALL(order), mt);
    int mxidx = 0;
    rep(i, order.size())
    {
        if (y[order[mxidx]].first < y[order[i]].first)
        {
            mxidx = i;
        }
    }

    auto starttime = clock();
    while ((double(clock() - starttime) / CLOCKS_PER_SEC < 1.8))
    {
        int ret = check(x, y, order);
        if (ret == -1)
        {
            cout << "Yes" << endl;
            for (auto &&idx : order)
            {
                rep(i, y[idx].first)
                {
                    cout << y[idx].second << " ";
                }
            }
            cout << endl;
            return 0;
        }
        int r = mt() % order.size();
        swap(order[mxidx], order[r]);
        mxidx = r;
        // cerr << y[order[mxidx]].first << endl;
    }

    cout << "No" << endl;
    return 0;
}