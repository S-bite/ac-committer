#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#define chmin(x, y) x = min(x, y);
using namespace std;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

bool check(vector<int> &v)
{
    rep(i, 6)
    {
        if (v[i] != i + 1)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    vector<int> v(6);
    rep(i, 6) v[i] = i + 1;
    map<int, vector<int>> mp;
    int cur = 0;
    do
    {
        mp[cur] = v;
        swap(v[(cur % 5)], v[(cur % 5) + 1]);
        cur++;
    } while (check(v) == false || cur % 5 != 0);
    cerr << cur << endl;
    int n;
    cin >> n;
    rep(i, 6)
    {
        cout << mp[n % cur][i];
    }
    cout << endl;
    return 0;
}
