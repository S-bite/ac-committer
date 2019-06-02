
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
bool cango(string s, int start, int end)
{
    int rock = 0;
    int space = 0;
    int retsp = 0;
    rep(i, start, end + 1)
    {
        if (s[i] == '#')
        {
            space = 0;
            rock++;
        }
        else
        {
            rock = 0;
            space++;
            retsp = max(retsp, space);
        }
        if (rock >= 2)
            return false;
    }

    return true;
}

bool canjump(string s, int start, int end)
{
    int space = 0;
    if (start > 0)
    {
        if (s[start - 1] == '.')
            space++;
    }
    rep(i, start, end + 2)
    {
        if (s[i] == '.')
            space++;
        else
            space = 0;
        if (space >= 3)
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    a--;
    b--;
    c--;
    d--;

    string s;
    cin >> s;
    if (c < d)
    {
        if (cango(s, a, c) && cango(s, b, d))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else
    {
        bool goa = cango(s, a, c), gob = cango(s, b, d);
        if (goa && gob && canjump(s, b, d))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}