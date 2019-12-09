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

int timegap(int a, int b)
{
    return abs(a - b);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    ll sxor[n + 1];
    ll ssum[n + 1];
    sxor[0] = 0;
    ssum[0] = 0;
    rep(i, 1, n + 1)
    {
        sxor[i] = sxor[i - 1] ^ a[i - 1];
        ssum[i] = ssum[i - 1] + a[i - 1];
        cerr << ssum[i] << endl;
    }
    int start = 0;
    int end = 0;
    ll ans = 0;
    while (end <= n)
    {
        if ((sxor[end] ^ sxor[start]) == (ssum[end] - ssum[start]))
        {
            cerr << (sxor[end] ^ sxor[start]) << " " << (ssum[end] - ssum[start]) << endl;
            ans += end - start;
            end++;
        }
        else
        {
            cerr << "else" << endl;
            do
            {
                start++;
            } while ((sxor[end] ^ sxor[start]) != (ssum[end] - ssum[start]));
        }
    }
    cout << ans << endl;
    return 0;
}
