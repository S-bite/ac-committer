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

void dump(deque<int> que)
{
    while (!que.empty())
    {
        cerr << que.front() << " ";
        que.pop_front();
    }
    cerr << endl;
}

int main()
{
    deque<int> que;
    int n;
    cin >> n;
    rep(i, n)
    {
        int t;
        cin >> t;
        que.push_back(t);
    }
    ll ans = 0;
    while (que.size() != 1)
    {
        //cerr << que.size() << " " << ans << endl;
        //dump(que);
        if (que.size() == 3)
        {
            ll a = que.front();
            que.pop_front();
            ll b = que.front();
            que.pop_front();
            ll c = que.front();
            que.pop_front();
            if (a + a + 1 + b < c + c + 1 + b)
            {
                ans += a + a + 1 + b;
                que.push_back(a + b + c + 2);
            }
            else
            {
                ans += c + c + 1 + b;
                que.push_back(a + b + c + 2);
            }
        }
        else
        {
            ll a = que.front();
            que.pop_front();
            ll b = que.front();
            que.pop_front();
            ll d = que.back();
            que.pop_back();
            ll c = que.back();
            que.pop_back();
            if (a + a + 1 + b < d + d + 1 + c)
            {
                ans += a + a + 1 + b;
                que.front() += (a + b + 2);
                que.push_back(c);
                que.push_back(d);
            }
            else
            {
                ans += d + d + 1 + c;
                que.back() += (c + d + 2);
                que.push_front(b);
                que.push_front(a);
            }
        }
    }
    cout << ans << endl;
    return 0;
}