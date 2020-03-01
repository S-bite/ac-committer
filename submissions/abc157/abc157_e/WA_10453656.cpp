#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#ifdef DEBUG
#define line() cout << "[" << __LINE__ << "] ";
#define dump(i) cout << #i ": " << i << " ";
#define dumpl(i) cout << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;

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
    map<int, int> mp;
    int N, Q;
    cin >> N;
    vector<SegmentTree<int>> segs(26, SegmentTree<int>(N, f, 0));
    string s;
    cin >> s;
    rep(i, N)
    {
        segs[s[i] - 'a'].update(i, 1);
    }
    cin >> Q;
    rep(i, Q)
    {
        // rep(j, N) cerr << mp[j] << " ";
        //cerr << endl;
        //rep(j, N) cerr << a[j] << " ";
        //cerr << endl;

        int type;
        cin >> type;
        if (type == 1)
        {
            int x;

            char c, old;
            cin >> x >> c;
            x--;
            old = s[x];
            s[x] = c;
            segs[c - 'a'].update(x, 1);
            segs[old - 'a'].update(x, 1);
        }
        else
        {
            int ans = 0;
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            rep(j, 26)
            {
                if (segs[j].query(x, y + 1) > 0)
                {
                    ans++;
                    // cerr << (char)('a' + j) << endl;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}