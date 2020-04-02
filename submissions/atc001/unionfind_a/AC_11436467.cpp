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
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int MAX = 510000;
const int MOD = 1000000007;
vector<vector<int>> group(101010);
vector<int> id(101010);

void unite(int a, int b)
{
    int ga = id[a];
    int gb = id[b];
    if (ga == gb)
        return;
    if (group[ga].size() < group[gb].size())
    {
        swap(ga, gb);
    }
    for (auto x : group[gb])
    {
        group[ga].push_back(x);
        id[x] = ga;
    }
    group[gb].clear();
}

bool same_root(int a, int b)
{
    //cerr << a << ":" << id[a] << endl;
    //cerr << b << ":" << id[b] << endl;
    return id[a] == id[b];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    rep(i, n)
    {
        group[i] = {i};
        id[i] = i;
    }
    int q;
    cin >> q;
    rep(i, q)
    {
        int p, a, b;
        cin >> p >> a >> b;
        //cerr << p << " " << a << " " << b << endl;
        if (p == 0)
        {
            unite(a, b);
        }
        else
        {
            if (same_root(a, b))
            {
                cout << "Yes" << '\n';
            }
            else
            {
                cout << "No" << '\n';
            }
        }
    }

    return 0;
}
