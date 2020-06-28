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

int n;
VI pena;
VVI gain;
int eval(VI &order)
{
    VI last(26, -1);
    int ret = 0;
    rep(i, n)
    {
        ret += gain[i][order[i]];
        last[order[i]] = i;
        rep(j, 26)
        {
            ret -= pena[j] * (i - last[j]);
        }
    }
    return ret;
}
void print(VI &order)
{
    for (auto &&x : order)
    {
        cout << x + 1 << endl;
    }
}

void search()
{
    typedef pair<int, VI> Tact;
    priority_queue<Tact> pque;
    VI base(n);
    VI last(26, -1);
    rep(i, n)
    {
        int cur = -IINF;
        int penasum = 0;
        rep(j, 26)
        {
            penasum += pena[j] * (i - last[j]);
        }
        rep(j, 26)
        {
            if (cur < gain[i][j] - penasum + pena[j] * (i - last[j]))
            {
                base[i] = j;
                cur = gain[i][j] - penasum + pena[j] * (i - last[j]);
            }
        }
        last[base[i]] = i;
    }
    print(base);
    cerr << eval(base) << endl;
    ;
}
int main()
{
    cin >> n;
    pena = VI(26);
    gain = VVI(n, VI(26));
    rep(i, 26)
    {
        cin >> pena[i];
    }
    rep(i, n)
    {
        rep(j, 26)
        {
            cin >> gain[i][j];
        }
    }
    search();
    return 0;
}