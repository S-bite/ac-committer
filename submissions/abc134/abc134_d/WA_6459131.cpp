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
    vector<int> a;
    a.push_back(-1111);
    rep(i, n)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }
    vector<int> b(n + 1, 0);
    b[0] = -1111;
    int m = 0;
    for (int i = n; i >= 1; i--)
    {
        int j = 1, tmp = 0;
        while (i * j < n)
        {
            tmp += a[i * j];
            j++;
        }
        tmp %= 2;
        b[i] = tmp;
        m += tmp;
    }
    cout << m << endl;
    rep(i, n + 1)
    {
        if (b[i] == 1)
        {
            cout << i << endl;
        }
    }

    return 0;
}
