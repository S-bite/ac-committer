#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const double EPS = 1e-3;
const double PI = 3.1415926535897932384626433832795028841971;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{
    deque<int> b;
    vector<int> ans;
    int n;
    cin >> n;
    rep(i, n)
    {
        int a;
        cin >> a;
        if (i % 2 == 0)
            b.push_back(a);
        else
            b.push_front(a);
    }
    while (!b.empty())
    {
        ans.push_back(b.front()), b.pop_front();
    }
    if (n % 2 == 1)
        reverse(ALL(ans));
    rep(i, n) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
