#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
random_device rnd;
mt19937 mt(rnd());

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int main()
{
    int q;
    cin >> q;
    deque<PII> que;
    rep(qq, q)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            char c;
            int x;
            cin >> c >> x;
            que.push_back({c - 'a', x});
        }
        else
        {
            int d;
            cin >> d;
            cerr << "delete " << d << endl;
            vector<ll> num(26, 0);
            while (d > 0 && !que.empty())
            {
                PII cur = que.front();
                if (cur.second > d)
                {
                    num[cur.first] += d;
                    que.front().second -= d;
                    d = 0;
                }
                else
                {
                    num[cur.first] += cur.second;
                    d -= cur.second;
                    que.pop_front();
                }
            }
            ll ans = 0;
            rep(i, 26)
            {
                ans += num[i] * num[i];
            }
            cout << ans << endl;
        }
    }

    return 0;
}