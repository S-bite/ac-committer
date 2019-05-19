#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <iomanip>
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
class UF
{
private:
public:
    UF *root;
    int value;
    UF(int n = 0)
    {
        root = this;
        value = n;
    }
    void showInfo(void)
    {
        cout << "rootNode:" << root << ",value:" << value << endl;
    }
};

void connectNode(UF *a, UF *b)
{
    while (b->root != b)
        b = b->root;
    while (a->root != a)
        a = a->root;

    if (a > b)
    {
        a->root = b;
    }
    if (a < b)
    {
        b->root = a;
    }
    return;
}
bool hasSameRoot(UF *a, UF *b)
{

    UF *pa = a;
    UF *pb = b;
    while (a->root != a)
        a = a->root;
    while (b->root != b)
        b = b->root;
    pa->root = a;
    pb->root = b;

    return a == b;
}
int main()
{
    ll m, k;
    cin >> m >> k;
    if (k == 0)
    {
        rep(i, (1 << m))
        {
            cout << i << " " << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
        return 0;
        string ans = "";
        map<ll, bool> mp;
        rep(i, (1 << m))
        {
            ll t = k ^ i;
            cerr << t << endl;
            if (t >= (1 << m))
            {
                cout << -1 << endl;
                return 0;
            }
            if (t > i)
                ans += to_string(i) + " " + to_string(t) + " " + to_string(i) + " " + to_string(t);
        }
        cout << ans << endl;
    }
    return 0;
}
