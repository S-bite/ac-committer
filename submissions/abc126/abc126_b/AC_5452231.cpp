#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
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

int main()
{
    char c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;
    int a = (c1 - '0') * 10 + (c2 - '0');
    int b = (c3 - '0') * 10 + (c4 - '0');
    bool x = (1 <= a && a <= 12);
    bool y = (1 <= b && b <= 12);
    if (x && y)
    {
        cout << "AMBIGUOUS" << endl;
    }
    else if (!x && y)
    {
        cout << "YYMM" << endl;
    }
    else if (x && !y)
    {
        cout << "MMYY" << endl;
    }
    else
    {
        cout << "NA" << endl;
        ;
    }

    return 0;
}
