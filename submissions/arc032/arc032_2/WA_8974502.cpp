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
    else
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
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    UF u[n];
    rep(i, n) u[i].value = i + 1;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        connectNode(&u[a], &u[b]);
    }
    map<UF *, bool> mp;
    int ans = 0;
    rep(i, n)
    {
        if (mp[u[i].root] == false)
        {
            ans++;
            mp[u[i].root] = true;
        }
    }
    cout << ans - 1 << endl;

    return 0;
}
