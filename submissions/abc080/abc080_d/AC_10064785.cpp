#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;
int main(int argc, char const *argv[])
{
    int n, c;
    cin >> n >> c;
    vector<vector<int>> v(n, vector<int>(3, 0));
    rep(i, n)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    sort(ALL(v));
    vector<int> a(c, 1 << 30);
    int ans = 0;
    rep(i, n)
    {
        rep(j, c)
        {
            if (j == ans)
            {
                a[ans] = v[i][1];
                // cerr << ans << " " << v[i][1] << " " << v[i][0] << endl;
                ans++;
                break;
            }
            if (a[j] < v[i][0])
            {
                //cerr << j << " " << v[i][1] << " " << v[i][0] << endl;
                a[j] = v[i][1];
                break;
            }
        }
        sort(ALL(a));
    }
    cout << ans << endl;
    return 0;
}
