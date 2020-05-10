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
    int n;
    ll k;
    cin >> n >> k;
    VI v(n);
    rep(i, n)
    {
        cin >> v[i];
        v[i]--;
    }
    int cur = 0;
    int warpnum = 0;
    map<int, bool> visited;
    visited[cur] = true;
    VI log = {0};
    while (k > 0)
    {

        cur = v[cur];
        warpnum++;
        k--;
        if (visited[cur] == true)
        {
            int ind = 0;
            rep(i, log.size())
            {
                if (log[i] == cur)
                {
                    ind = i;
                    break;
                }
            }
            k %= (warpnum - ind);
        }
        visited[cur] = true;
        log.push_back(cur);
    }
    rep(i, k)
    {
        cur = v[cur];
    }
    cout << cur + 1 << endl;
    return 0;
}