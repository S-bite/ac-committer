#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
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

    while (a->root != a)
        a = a->root;
    while (b->root != b)
        b = b->root;
    return a == b;
}
int main(int argc, char const *argv[])
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<ll> a(n + 2);
    rep(i, n + 2) a[i] = 1;
    a[0] = 0;
    a[n + 1] = 0;
    map<char, vector<int>> mp;
    char t[q], d[q];
    rep(i, 1, n + 1)
    {
        mp[s[i - 1]].push_back(i);
    }

    rep(i, q)
    {
        cin >> t[i] >> d[i];
    }
    rep(i, q)
    {
        auto _a = a;
        for (auto ind : mp[t[i]])
        {
            if (d[i] == 'L')
            {
                a[ind - 1] += _a[ind];
                a[ind] = 0;
            }
            else
            {
                a[ind + 1] += _a[ind];
                a[ind] = 0;
            }
        }
    }
    cout << n - (a[0] + a[n + 1]) << endl;
    return 0;
}
