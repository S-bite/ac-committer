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

const int N = 100;

void update(VVI &g, int y, int x, int h)
{
    rep(i, N) rep(j, N)
    {
        g[i][j] += max(0, h - abs(y - i) - abs(x - j));
    }
}

int eval(VVI &g, VVI &f)
{
    int ret = 200000000;
    rep(i, N) rep(j, N)
    {
        ret -= abs(g[i][j] - f[i][j]);
    }
    return ret;
}

int main()
{
    auto start = clock();
    VVI target(N, VI(N, 0));
    rep(i, N) rep(j, N)
    {
        cin >> target[i][j];
    }
    VVI best;
    int bestscore = 0;
    int loop = 0;
    while (double(clock() - start) / CLOCKS_PER_SEC < 5.9)
    {
        VVI g(N, VI(N, 0));
        VVI cur;
        rep(i, 1000)
        {
            int y = mt() % N;
            int x = mt() % N;
            int h = mt() % N + 1;
            cur.push_back({y, x, h});
            update(g, y, x, h);
        }
        int curscore = eval(g, target);
        if (curscore > bestscore)
        {
            bestscore = curscore;
            best = cur;
        }
        loop++;
    }
    cout << best.size() << endl;
    rep(i, best.size())
    {
        cout << best[i][1] << " " << best[i][0] << " " << best[i][2] << endl;
    }
    cerr << loop << endl;
    return 0;
}
