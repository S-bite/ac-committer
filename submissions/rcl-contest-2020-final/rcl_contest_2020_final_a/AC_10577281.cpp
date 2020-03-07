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

int n, m;
vector<int> d;
void print_dice(vector<int> &d)
{
    rep(i, 6) cout << d[i] << " ";
    cout << endl;
}
void update(vector<int> &d)
{
    rep(i, 6)
    {

        if (d[i] < 3)
        {
            d[i] += 3;
            return;
        }
        /*if (d[i] <= 2)
        {
            d[i] = 5;
            return;
        }
        if (d[i] <= 4)
        {
            d[i] = 6;
            return;
        }*/
    }
}
int main(int argc, char const *argv[])
{
    d.resize(6);
    rep(i, 6)
    {
        d[i] = i + 1;
    }
    cin >> n >> m;
    int pos = 0;
    int score = 0;
    rep(i, m)
    {
        int res, v;
        print_dice(d);
        cin >> res >> v >> pos;
        score += v;
        if (pos == n)
        {
            pos = 0;
        }
        update(d);
    }
    return 0;
}
