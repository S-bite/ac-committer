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
bool isprime(int n)
{
    int k = 2;
    while (k * k <= n)
    {
        if (n % k == 0)
        {
            return false;
        }
        k++;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int a[101010];
    a[0] = a[1] = 0;
    rep(i, 2, 101010)
    {
        if (i % 2 == 0)
        {
            a[i] = a[i - 1];
        }
        else
        {
            if (isprime(i) && isprime((i + 1) / 2))
            {
                a[i] = a[i - 1] + 1;
            }
            else
            {
                a[i] = a[i - 1];
            }
        }
    }
    int q;
    cin >> q;
    rep(i, q)
    {
        int l, r;
        cin >> l >> r;
        cout << a[r + 1] - a[l - 1] << endl;
    }
    return 0;
}
