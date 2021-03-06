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
            sz *= 2;
        seg.assign(2 * sz, M1);
    }
    void set(int k, const Monoid &x)
    {
        seg[k + sz] = x;
    }
    void build()
    {
        for (int k = sz - 1; k > 0; k++)
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

int f(int a, int b)
{
    return a + b;
}

int main()
{
    ll h, w, m;
    cin >> h >> w >> m;
    vector<PII> p(m);
    rep(i, m)
    {
        cin >> p[i].first >> p[i].second;
    }
    if (m == 0)
    {
        cout << h * w << endl;
        return 0;
    }
    sort(ALL(p));
    if (h == 1 && w == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    else if (w == 1) // |
    {
        if (m == 0)
        {
            cout << h << endl;
            return 0;
        }
        assert(p.at(0).second == 1);
        cout << p[0].first - 1 << endl;
        return 0;
    }
    else if (h == 1) //-
    {
        if (m == 0)
        {
            cout << w << endl;
            return 0;
        }
        assert(p.at(0).first == 1);
        cout << p[0].second - 1 << endl;
        return 0;
    }
    SegmentTree<int> seg(w + 10, f, 0);
    int cur = p[0].first;
    vector<int> prev;
    vector<int> next;
    ll b = m;
    rep(i, m)
    {
        if (p[i].first == cur)
        {
            b += seg.query(p[i].second + 1, w);

            next.push_back(p[i].second);
        }
        else
        {
            cur = p[i].first;
            rep(j, next.size())
            {
                seg.update(next[j], 1);
            }
            next.clear();
            b += seg.query(p[i].second + 1, w);

            next.push_back(p[i].second);
        }
    }
    cout << h * w - b << endl;
    return 0;
}