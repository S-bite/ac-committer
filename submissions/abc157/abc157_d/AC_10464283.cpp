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
class UF
{
private:
public:
    UF *root;
    int value;
    UF(int n = 1)
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
        b->value += a->value;
    }
    if (a < b)
    {
        b->root = a;
        a->value += b->value;
    }
    return;
}

int gnum(UF *a)
{
    UF *pa = a;
    while (a->root != a)
        a = a->root;
    pa->root = a;
    return a->root->value;
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
    int n, m, k;
    cin >> n >> m >> k;

    UF u[n];
    map<int, vector<int>> g;
    map<int, vector<int>> block;
    map<pair<int, int>, bool> isFriend;
    map<pair<int, int>, bool> isBlock;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
        connectNode(&u[a], &u[b]);
        isFriend[{a, b}] = true;
        isFriend[{b, a}] = true;
    }
    rep(i, k)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        isBlock[{a, b}] = true;
        isBlock[{b, a}] = true;
        block[a].push_back(b);
        block[b].push_back(a);
    }
    rep(i, n)
    {
        int ans = gnum(&u[i]) - g[i].size() - 1;
        for (auto x : block[i])
        {
            if (hasSameRoot(&u[i], &u[x]))
                ans--;
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}