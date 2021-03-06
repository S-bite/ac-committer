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
int pena_sum;
VI gain_sum;
int eval(VI &order)
{
    VI last(26, -1);
    int ret = 0;
    int cur_pena = pena_sum;
    rep(i, n)
    {
        ret += gain[i][order[i]];
        cur_pena -= pena[order[i]] * (i - last[order[i]]);
        last[order[i]] = i;
        ret -= cur_pena;
        cur_pena += pena_sum;
    }
    return ret;
}
int eval_diff(VI &order, int start, VVI &log)
{
}
void print(VI &order)
{
    for (auto &&x : order)
    {
        cout << x + 1 << endl;
    }
}

int choice_weighted()
{
    int r = mt() % pena_sum;
    rep(i, 26)
    {
        r -= pena[i];
        if (r <= 0)
            return i;
    }
}
int choice_weighted_gain(int turn)
{
    int r = mt() % gain_sum[turn];
    rep(i, 26)
    {
        r -= gain[turn][i];
        if (r <= 0)
            return i;
    }
}

void search()
{
    auto starttime = clock();
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
    auto best = base;
    int bscore = eval(base);
    pque.push({eval(base), base});
    int width = 64;
    cerr << bscore << endl;
    int loopnum = 0;
    while (double(clock() - starttime) / CLOCKS_PER_SEC < 1.9)
    {
        auto next = pque;
        while (!pque.empty())
        {

            auto cur = pque.top();
            pque.pop();
            int r1 = mt() % n;
            int r2 = mt() % n;
            swap(cur.second[r1], cur.second[r2]);
            cur.first = eval(cur.second);
            next.push(cur);

            cur.second[r1] = choice_weighted_gain(r1);
            cur.second[r2] = choice_weighted_gain(r2);
            cur.first = eval(cur.second);
            next.push(cur);
        }

        rep(i, min(width, (int)next.size()))
        {
            pque.push(next.top());
            next.pop();
        }
        loopnum++;
    }
    cerr << "ok" << endl;
    best = pque.top().second;
    bscore = pque.top().first;
    print(best);
    cerr << bscore << endl;
    cerr << loopnum << endl;
}
int main()
{
    cin >> n;
    pena = VI(26);
    gain = VVI(n, VI(26));
    gain_sum = VI(n, 0);
    rep(i, 26)
    {
        cin >> pena[i];
        pena_sum += pena[i];
    }
    rep(i, n)
    {
        rep(j, 26)
        {
            cin >> gain[i][j];
            gain_sum[i] += gain[i][j];
        }
    }
    search();
    return 0;
}
