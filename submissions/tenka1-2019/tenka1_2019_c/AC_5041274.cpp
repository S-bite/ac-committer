#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
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
    string s;
    cin >> n >> s;
    int a = 0;
    rep(i, s.size())
    {
        if (s[i] == '#')
        {
            a++;
        }
    }
    int ans = a;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '#')
        {
            a--;
        }
        else
            a++;
        ans = min(a, ans);
        // cerr << s[i] << "," << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
