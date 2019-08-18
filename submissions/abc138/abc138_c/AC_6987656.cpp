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
    int n;
    cin >> n;
    vector<double> v(n, 0.0);
    rep(i, n) cin >> v[i];
    sort(ALL(v));
    while (v.size() != 1)
    {
        vector<double> next;
        rep(i, 2, v.size())
        {
            next.push_back(v[i]);
        }
        next.push_back((v[0] + v[1]) / 2);
        v = next;
        sort(ALL(v));
    }
    printf("%f\n", v[0]);
    return 0;
}
