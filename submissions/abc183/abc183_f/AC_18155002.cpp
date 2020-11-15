#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
struct G
{
    int num;
    vector<int> mem;
    map<int, int> mp;
};
vector<int> id(201010);

void merge(vector<G> &group, int a, int b)
{
    if (id[a] == id[b])
    {
        return;
    }
    if (group[id[a]].num > group[id[b]].num)
    {

        group[id[a]].num += group[id[b]].num;
        for (const auto &[key, value] : group[id[b]].mp)
        {
            group[id[a]].mp[key] += value;
        }
        for (auto &&m : group[id[b]].mem)
        {
            group[id[a]].mem.push_back(m);
            id[m] = id[a];
        }
    }
    else
    {
        group[id[b]].num += group[id[a]].num;
        for (const auto &[key, value] : group[id[a]].mp)
        {
            group[id[b]].mp[key] += value;
        }
        for (auto &&m : group[id[a]].mem)
        {
            group[id[b]].mem.push_back(m);
            id[m] = id[b];
        }
    }
}
int main()
{
    int n, q;
    cin >> n >> q;
    vector<G> group(n);
    rep(i, n)
    {

        group[i].mp.clear();
        int t;
        cin >> t;
        t--;
        group[i].num = 1;
        group[i].mem.push_back(i);
        group[i].mp[t] = 1;
        id[i] = i;
    }
    rep(i, q)
    {
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        y--;
        if (t == 1)
        {
            merge(group, x, y);
        }
        else
        {
            cout << group[id[x]].mp[y] << endl;
        }
    }
    return 0;
}