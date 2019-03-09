#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#ifdef DEBUG
#define line() cout << "[" << __LINE__ << "] ";
#define dump(i) cout << #i ": " << i << " ";
#define dumpl(i) cout << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;

ll g(ll n)
{
    switch (n % 4)
    {
    case 0:
        return n;
    case 1:
        return 1;
    case 2:
        return n + 1;
    case 3:
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    ll a, b;
    cin >> a >> b;
    cout << (g(a - 1) ^ g(b)) << endl;

    return 0;
}

//0 1 2 3 4 5 6 7 8 0 1 3 0 4
