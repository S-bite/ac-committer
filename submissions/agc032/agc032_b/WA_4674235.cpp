#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] " << endl;
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
    if (n == 3)
    {
        cout << 2 << endl;
        cout << 1 << " " << 3 << endl;
        cout << 2 << " " << 3 << endl;
        return 0;
    }
    int m;

    if (n % 2 == 0)
    {
        m = (n - 2) * n / 2;
        cout << m << endl;
        rep(i, n) rep(j, i + 1, n)
        {
            if (i == j || (i + 1) + (j + 1) == n + 1)
                continue;
            cout << i + 1 << " " << j + 1 << endl;
        }
        return 0;
    }
    else
    {
        m = (n - 3) * (n - 1) / 2 + (n - 1);
        cout << m + 1 << endl;
        rep(i, n - 1) rep(j, i + 1, n - 1)
        {
            if (i == j || (i + 1) + (j + 1) == n)
                continue;
            cout << i + 1 << " " << j + 1 << endl;
        }
        rep(i, n)
        {
            cout << n << " " << i + 1 << endl;
        }
        return 0;
    }
    return 0;
}
