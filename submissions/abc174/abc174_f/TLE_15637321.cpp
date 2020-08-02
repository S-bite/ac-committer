#pragma GCC optimize("Ofast")
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
    vector<int> tmp;
    rep(i, n)
    {
        int t;
        cin >> t;
        tmp.push_back(t);
    }

    vector<int> col(n + 1, 0);
    col[tmp[0]]++;
    int num = 1;
    int cl = 0, cr = 0;
    vector<pair<pair<int, int>, int>> query(q);
    rep(i, q)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        query[i] = {{l, -r}, i};
    }
    sort(ALL(query));
    VI ans(q, 0);
    rep(i, q)
    {
        int l = query[i].first.first;
        int r = -query[i].first.second;

        if (r < cr)
        {
            while (r != cr)
            {
                col[tmp[cr]]--;
                if (col[tmp[cr]] == 0)
                    num--;
                cr--;
            }
        }
        if (r > cr)
        {
            while (r != cr)
            {

                cr++;
                if (col[tmp[cr]] == 0)
                    num++;
                col[tmp[cr]]++;
            }
        }

        if (l > cl)
        {
            while (l != cl)
            {
                col[tmp[cl]]--;
                if (col[tmp[cl]] == 0)
                    num--;
                cl++;
            }
        }

        if (l < cl)
        {
            while (l != cl)
            {
                cl--;
                if (col[tmp[cl]] == 0)
                    num++;
                col[tmp[cl]]++;
            }
        }
        assert(cl == l && cr == r);
        ans[query[i].second] = num;
    }
    rep(i, q)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}