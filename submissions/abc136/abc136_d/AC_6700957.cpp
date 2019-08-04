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
#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)

int ordnum(int n)
{
    int ret = 0;
    while (n != 0)
    {
        ret++;
        n /= 10;
    }
    return ret;
}

int main()
{
    string s;
    cin >> s;
    int a[s.size()];
    rep(i, s.size()) a[i] = 0;
    int r[2] = {0, 0};
    int l[2] = {0, 0};
    int cnt = 0;
    int pos = -1;
    int i = 0;
    while (i < s.size())
    {
        rep(j, 2)
        {
            r[j] = 0;
            l[j] = 0;
        }
        cnt = 0;
        while ((s[i] == 'R'))
        {
            r[cnt % 2]++;
            cnt++;
            i++;
        }
        pos = i - 1;
        a[pos] += r[0];
        a[pos + 1] += r[1];
        cnt = 0;
        while ((s[i] == 'L') && i < s.size())
        {
            l[cnt % 2]++;
            cnt++;
            i++;
        }
        a[pos] += l[1];
        a[pos + 1] += l[0];
    }
    rep(i, s.size()) cout << a[i] << " ";
    cout << endl;
    return 0;
}