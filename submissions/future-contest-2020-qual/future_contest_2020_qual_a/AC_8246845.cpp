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

struct Robot
{
    int y, x;
    char angle;
};

struct Block
{
    int y, x;
};

int main(int argc, char const *argv[])
{
    int n, m, b;
    cin >> n >> m >> b;
    int gy, gx;
    cin >> gy >> gx;
    vector<Robot> robots(m);
    vector<Block> blocks(b);
    rep(i, m)
    {
        cin >> robots[i].y >> robots[i].x >> robots[i].angle;
    }

    rep(i, m)
    {
        cin >> blocks[i].y >> blocks[i].x;
    }
    cout << 0 << endl;
    return 0;
}
