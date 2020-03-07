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
vector<int> actual;
void print_dice(vector<int> &d)
{
    rep(i, 6) cout << d[i] << " ";
    cout << endl;
}

void update6(vector<int> &d)
{
    rep(i, 6)
    {

        if (d[i] != 6)
        {
            d[i] = 6;
            return;
        }
    }
}
void update1(vector<int> &d)
{
    rep(i, 6)
    {

        if (d[i] != 1)
        {
            d[i] = 1;
            return;
        }
    }
}

void update(vector<int> &d, int pos)
{
    if (pos + 5 >= n)
    {
        update1(d);
        return;
    }
    else
    {
        int reward = 0;
        rep(i, pos + 1, min(n, pos + 12))
        {
            reward += actual[i];
        }
        //cerr << reward / 12 << endl;
        if (reward / 12 >= 100)
        {
            update1(d);
        }
        else
        {
            update6(d);
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;

    d.resize(6);
    actual.resize(n + 1, 0);
    rep(i, 6)
    {
        d[i] = i + 1;
    }
    int pos = 0;
    int score = 0;
    rep(i, m)
    {
        int res, v;
        print_dice(d);
        cin >> res >> v >> pos;
        score += v;
        actual[pos] = v;
        if (pos == n)
        {
            pos = 0;
        }

        update(d, pos);
    }
    return 0;
}
