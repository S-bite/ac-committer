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
    int h, w, n;
    cin >> h >> w >> n;
    int y, x;
    cin >> y >> x;
    string s, t;
    cin >> s >> t;
    int r = y, c = x;
    rep(i, n)
    {
        if (s[i] == 'U')
            r--;
        if (r == 0)
        {
            cerr << "U" << endl;

            cout << "NO" << endl;
            return 0;
        }
        if (t[i] == 'D')
            r = min(h, r + 1);
    }
    r = y, c = x;
    rep(i, n)
    {
        if (s[i] == 'D')
            r++;
        if (r == h + 1)
        {
            cerr << "D" << endl;

            cout << "NO" << endl;
            return 0;
        }
        if (t[i] == 'U')
            r = max(1, r - 1);
    }
    r = y, c = x;
    rep(i, n)
    {
        if (s[i] == 'L')
            c--;
        if (c == 0)
        {
            cerr << "L" << endl;

            cout << "NO" << endl;
            return 0;
        }
        if (t[i] == 'R')
            c = min(w, c + 1);
    }

    r = y, c = x;
    rep(i, n)
    {
        if (s[i] == 'R')
            c++;
        if (c == w + 1)
        {
            cerr << "R" << endl;
            cout << "NO" << endl;
            return 0;
        }
        if (t[i] == 'L')
            c = max(1, c - 1);
    }
    cout << "YES" << endl;
    return 0;
}
