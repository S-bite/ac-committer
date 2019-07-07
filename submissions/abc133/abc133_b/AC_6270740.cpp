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
int n, d;

bool isok(vector<int> &a, vector<int> &b)
{
    int sum = 0;
    rep(i, d)
    {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    //  cerr << sum << endl;
    int pow = 1;
    while (pow * pow < sum)
        pow += 1;
    return pow * pow == sum;
}

int main(int argc, char const *argv[])
{
    cin >> n >> d;
    vector<vector<int>> v(n, vector<int>(d, 0));
    rep(i, n) rep(j, d) cin >> v[i][j];
    int ans = 0;
    rep(i, n) rep(j, i + 1, n)
    {
        if (isok(v[i], v[j]))
            ans++;
    }
    cout << ans << endl;
    return 0;
}
