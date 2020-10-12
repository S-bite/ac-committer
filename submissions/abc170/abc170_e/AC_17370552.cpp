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

int main()
{
    int n, q;
    cin >> n >> q;
    vector<priority_queue<PII>> kinder(202020);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> top;
    vector<int> pos(n + 1);
    vector<int> rate(n + 1);
    rep(i, 1, n + 1)
    {
        int a, b;
        cin >> a >> b;
        pos[i] = b;
        rate[i] = a;
        kinder[b].push({ a, i });
    }
    rep(i, 202020)
    {
        if (kinder[i].empty())
            continue;
        top.push(make_tuple(kinder[i].top().first, kinder[i].top().second, i));
    }
    rep(i, q)
    {
        int id, to;
        cin >> id >> to;
        int from = pos[id];
        pos[id] = to;
        kinder[to].push({ rate[id], id });
        // cerr << "move " << id << " to " << to << " rate:" << rate[id] << endl;
        top.push(make_tuple(kinder[to].top().first, kinder[to].top().second, to));
        while (!kinder[from].empty() && pos[kinder[from].top().second] != from) {
            int r, i;
            tie(r, i) = kinder[from].top();
            //cerr << "del kinder " << r << " " << i << endl;
            kinder[from].pop();
        }
        top.push(make_tuple(kinder[from].top().first, kinder[from].top().second, from));

        while (!top.empty() && (get<2>(top.top()) != pos[get<1>(top.top())] || get<0>(top.top()) != kinder[pos[get<1>(top.top())]].top().first)) {
            int r, i, k;
            tie(r, i, k) = top.top();
            // cerr << "del top " << r << " " << i << " " << k << endl;
            top.pop();
        }
        cout << get<0>(top.top()) << endl;
    }

    return 0;
}