
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

    string s;
    cin >> s;
    ll a = 0;
    ll ans = 0;
    rep(i, s.size() - 1)
    {
        //cerr << s[i] << " ";
        if (s[i] == 'A')
        {
            a++;
        }
        else
        {
            if (s[i] == 'B' && s[i + 1] == 'C')
            {
                ans += a;
                i++;
            }
            else
            {
                a = 0;
            }
        }
        //cerr << a << "," << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
