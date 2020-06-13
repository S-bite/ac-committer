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

VL w, v;

//from:https://ei1333.github.io/algorithm/segment-tree.html
////////////////////////////////////////
template <typename Monoid>
struct SegmentTree
{
    using F = function<Monoid(Monoid, Monoid)>;

    int sz;
    vector<Monoid> seg;

    const F f;
    const Monoid M1;

    SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1)
    {
        sz = 1;
        while (sz < n)
            sz <<= 1;
        seg.assign(2 * sz, M1);
    }

    void set(int k, const Monoid &x)
    {
        seg[k + sz] = x;
    }

    void build()
    {
        for (int k = sz - 1; k > 0; k--)
        {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid &x)
    {
        k += sz;
        seg[k] = x;
        while (k >>= 1)
        {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b)
    {
        Monoid L = M1, R = M1;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1)
        {
            if (a & 1)
                L = f(L, seg[a++]);
            if (b & 1)
                R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) const
    {
        return seg[k + sz];
    }
};
/////////////////////////////////////////////
int f(int a, int b)
{
    return max(a, b);
}
SegmentTree<int> seg(101010 * 18, f, 0);
void solve(VI &items, int l)
{
    //cerr << "**" << endl;
    for (auto &&x : items)
    {
        //  cerr << x << " ";
    }
    int n = items.size();
    if (n == 1)
    {
        if (w[items[0]] <= l)
        {
            cout << v[items[0]] << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        return;
    }
    VI log;
    map<int, int> mp;
    rep(i, 1 << (n / 2))
    {
        int curw = 0, curv = 0;
        rep(j, n / 2)
        {
            if (((i >> j) & 1) == 1)
            {
                curw += w[items[j]];
                curv += v[items[j]];
            }
        }
        //cerr << "-" << curv << " " << curw << " " << l << endl;
        if (curv > mp[curw])
        {
            seg.update(curw, curv);
            log.push_back(curw);
            mp[curw] = curv;
        }
    }
    int ans = -1;

    rep(i, 1 << (n - (n / 2)))
    {
        int curw = 0, curv = 0;
        rep(j, n - (n / 2))
        {
            if (((i >> j) & 1) == 1)
            {
                curw += w[items[j + n / 2]];
                curv += v[items[j + n / 2]];
            }
        }
        if (curw > l)
            continue;
        //  cerr << "+" << curv << " " << curw << " " << l << endl;
        chmax(ans, curv + seg.query(0, l - curw + 1));
    }
    for (auto &&x : log)
    {
        seg.update(x, 0);
    }
    cout << ans << endl;
}

int main()
{
    int n;
    cin >> n;
    w = VL(n);
    v = VL(n);
    rep(i, n)
    {
        cin >> v[i] >> w[i];
    }
    int q;
    cin >> q;
    rep(i, q)
    {
        int a, l;
        cin >> a >> l;
        VI items;
        while (a != 1)
        {
            items.push_back(a - 1);
            a /= 2;
        }
        items.push_back(a - 1);
        solve(items, l);
    }
    return 0;
}