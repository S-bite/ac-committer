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
    int n, k;
    cin >> n >> k;
    if ((n - 1) * (n - 2) / 2 < k)
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        rep(i, 1, n)
        {
            cout << i << " " << n << endl;
        }
        int now = (n - 1) * (n - 2) / 2;
        int x = 1;
        int y = 2;
        while (now != k)
        {
            cout << x << " " << y << endl;
            now--;
            x++;
            if (x == y)
                x++;
            if (x >= n)
            {
                x = 1;
                y++;
            }
        }
    }

    return 0;
}
