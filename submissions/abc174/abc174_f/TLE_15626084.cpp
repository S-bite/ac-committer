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

//from:https://beet-aizu.hatenablog.com/entry/2017/09/14/122311 (little modified)
template <typename T, typename E>
struct SegmentTree
{
    typedef function<T(T &, T &)> F;
    typedef function<T(T &, E &)> G;
    int n;
    F f;
    G g;
    T d1;
    vector<T> dat;
    SegmentTree(int n_, F f, G g, T d1,
                vector<T> v = vector<T>())
    {
        this->f = f;
        this->g = g;
        this->d1 = d1;
        init(n_);
        if (n_ == (int)v.size())
            build(n_, v);
    }
    void init(int n_)
    {
        n = 1;
        while (n < n_)
            n *= 2;
        dat.clear();
        dat.resize(2 * n - 1, d1);
    }
    void build(int n_, vector<T> v)
    {
        for (int i = 0; i < n_; i++)
            dat[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--)
            dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
    void update(int k, E a)
    {
        k += n - 1;
        dat[k] = g(dat[k], a);
        while (k > 0)
        {
            k = (k - 1) / 2;
            dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    T query(int a, int b, int k, int l, int r)
    {
        if (r <= a || b <= l)
            return d1;
        if (a <= l && r <= b)
            return dat[k];
        T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return f(vl, vr);
    }
    T query(int a, int b)
    {
        return query(a, b, 0, 0, n);
    }
};

///////////////////

int main()
{
    int n, q;
    cin >> n >> q;
    SegmentTree<vector<int>, vector<int>> seg(
        n,
        [](vector<int> &a, vector<int> &b) {
            vector<int> ret = a;
            for (int x : b)
            {
                ret.push_back(x);
            }
            sort(ALL(ret));
            ret.erase(unique(ret.begin(), ret.end()), ret.end());
            return ret;
        },

        [](vector<int> &a, vector<int> &b) { return b; },
        {});
    rep(i, n)
    {
        int t;
        cin >> t;
        seg.update(i, {t});
    }

    map<pair<int, int>, int> mp;

    rep(i, q)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (mp.find({l, r}) != mp.end())
        {
            cout << mp[{l, r}] << endl;
        }
        else
        {
            auto ret = seg.query(l, r + 1);
            int ans = ret.size();
            cout << ans << endl;
            mp[{l, r}] = ans;
        }
    }
    return 0;
}