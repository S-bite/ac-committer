#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const double EPS = 1e-3;
const double PI = 3.1415926535897932384626433832795028841971;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

bool dfs(string &a, string &b, vector<int> &v, int depth, bool canskip)
{
    if (canskip)
    {
        if (a == b)
        {
            return true;
        }
    }
    if (depth == 3)
    {
        return a == b;
    }
    for (int i : v)
    {
        for (int j : v)
        {
            swap(a[i], a[j]);
            if (dfs(a, b, v, depth + 1, canskip))
            {
                return true;
            }
            swap(a[i], a[j]);
        }
    }
    return false;
}

int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> v;
    bool canskip = false;
    map<char, bool> mp;
    map<char, int> num;
    rep(i, a.size())
    {
        if (a[i] != b[i])
        {
            v.push_back(i);
        }
        canskip |= mp[a[i]];
        mp[a[i]] = true;
        num[a[i]]++;
        num[b[i]]--;
    }
    if (v.size() > 6)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (num[c] != 0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (dfs(a, b, v, 0, canskip))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}