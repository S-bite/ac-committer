#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
ll merge_cnt(vector<int> &a)
{
    int n = a.size();
    if (n <= 1)
    {
        return 0;
    }

    ll cnt = 0;
    vector<int> b(a.begin(), a.begin() + n / 2);
    vector<int> c(a.begin() + n / 2, a.end());

    cnt += merge_cnt(b);
    cnt += merge_cnt(c);

    int ai = 0, bi = 0, ci = 0;
    // merge の処理
    while (ai < n)
    {
        if (bi < b.size() && (ci == c.size() || b[bi] <= c[ci]))
        {
            a[ai++] = b[bi++];
        }
        else
        {
            cnt += n / 2 - bi;
            a[ai++] = c[ci++];
        }
    }
    return cnt;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> v(n);
    rep(i, n)
    {
        cin >> v[i];
    }
    auto w = v;
    sort(ALL(v));

    map<int, int> mp;
    rep(i, n) mp[v[i]] = i;
    int ans = 0;
    rep(i, n)
    {
        a[i] = mp[w[i]];
        if ((i % 2) != (a[i] % 2))
            ans++;
    }
    cout << ans / 2 << endl;
    return 0;
}
