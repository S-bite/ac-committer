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
    int q, l;
    cin >> q >> l;
    deque<PII> que;
    ll sz = 0;
    rep(qq, q)
    {
        string ty;
        cin >> ty;
        if (ty == "Push")
        {
            int n, m;
            cin >> n >> m;
            que.push_front({m, n});
            sz += n;
            if (sz > l)
            {
                cout << "FULL" << endl;
                return 0;
            }
        }
        else if (ty == "Pop")
        {
            int d;
            cin >> d;
            sz -= d;
            if (sz < 0)
            {
                cout << "EMPTY" << endl;
                return 0;
            }
            while (d > 0 && !que.empty())
            {
                PII cur = que.front();
                if (cur.second > d)
                {
                    que.front().second -= d;
                    d = 0;
                }
                else
                {
                    d -= cur.second;
                    que.pop_front();
                }
            }
        }
        else if (ty == "Top")
        {
            if (sz == 0)
            {
                cout << "EMPTY" << endl;
                return 0;
            }
            cout << que.front().first << endl;
        }
        else
        {

            cout << sz << endl;
        }
    }
    cout << "SAFE" << endl;

    return 0;
}
