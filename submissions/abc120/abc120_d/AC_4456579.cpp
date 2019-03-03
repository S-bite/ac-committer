#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
struct UF
{
    UF *root;
    ll con;
};
UF *root(UF *u)
{
    UF *_u = u;
    while (u->root != u)
        u = u->root;
    _u->root = u;
    return u;
}

bool isconnected(UF *a, UF *b)
{
    return (root(a) == root(b));
}

void unite(UF *a, UF *b)
{
    if (isconnected(a, b))
        return;
    a = root(a);
    b = root(b);
    b->root = a;
    a->con += b->con;
}
int main()
{
    ll n, m;
    cin >> n >> m;
    UF u[n];
    rep(i, n)
    {
        u[i] = UF{&u[i], 1};
    }
    pair<int, int> p[m];
    ll rest = n;
    ll ans[m];
    ans[m - 1] = n * (n - 1) / 2;
    //ans[0] = 0;
    rep(i, m) cin >> p[i].first >> p[i].second;
    for (int i = m - 2; i >= 0; i--)
    {
        int a = p[i + 1].first - 1, b = p[i + 1].second - 1;
        // cout << a << "," << b << endl;

        if (isconnected(&u[a], &u[b]))
        {
            ans[i] = ans[i + 1];
            continue;
        }
        //        cout << root(&u[a])->con << endl;
        ans[i] = ans[i + 1] - root(&u[a])->con * root(&u[b])->con;

        unite(&u[a], &u[b]);

        // rest -= u[a].con - 1;
        //cout << "r:" << rest << endl;
    }
    rep(i, m) cout << ans[i] << endl;
    return 0;
}