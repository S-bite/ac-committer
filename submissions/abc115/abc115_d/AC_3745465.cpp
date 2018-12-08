#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ll long long
using namespace std;

string b(int n)
{
    if (n == 0)
        return "P";
    return "B" + b(n - 1) + "P" + b(n - 1) + "B";
}
ll bnum(int n)
{
    if (n == 0)
        return 1ll;
    return 3ll + 2 * bnum(n - 1);
}
ll pnum(int n)
{
    if (n == 0)
        return 1ll;
    return 1ll + 2 * pnum(n - 1);
}
ll solve(ll n, ll x)
{
    ll ret = 0;
    if (n == 0)
        return 1ll;
    if (x == 1)
        return 0ll;
    x -= 1;
    if (x <= bnum(n - 1))
    {
        return ret + solve(n - 1, x);
    }
    x -= bnum(n - 1);
    ret += pnum(n - 1);
    if (x == 1)
        return 1ll + ret;
    ret += 1;
    x -= 1;

    if (x <= bnum(n - 1))
    {
        return ret + solve(n - 1, x);
    }
    x -= bnum(n - 1);
    ret += pnum(n - 1);
    return ret;
}
int main()
{
    ll n, x;

    cin >> n >> x;

    cout << solve(n, x) << endl;

    return 0;
}