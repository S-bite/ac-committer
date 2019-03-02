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
int a[50];
struct Pair
{
    int score;
    int cost;
    int a;
    int b;
};
Pair getpair(int s)
{
    Pair ret = Pair{-1, 1000, -1, -1};
    rep(i, 50) rep(j, i + 1, 50)
    {
        if (a[i] == a[j] && a[i] != -1)
        {
            Pair p = Pair{a[i], abs(i - j) + min(abs(i - s), abs(j - s)), i, j};
            if (p.score > ret.score || (p.score == ret.score && p.cost < ret.cost))
            {
                ret = p;
            }
        }
    }
    if (abs(ret.a - s) > abs(ret.b - s))
    {
        int t = ret.a;
        ret.a = ret.b;
        ret.b = t;
    }
    return ret;
}
int search(int s, int q)
{
    int ret = -1, dist = 51;
    rep(i, 50)
    {
        if (a[i] == q && abs(s - i) < dist)
        {
            dist = abs(s - i);
            ret = i;
        }
    }
    return ret;
}
int nearest(int s)
{
    int ret = -1, dist = 51;
    rep(i, 50)
    {
        if (a[i] == -1 && abs(s - i) < dist)
        {
            dist = abs(s - i);
            ret = i;
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    int n = 50, t = 10000, _;
    cin >> _ >> _;

    rep(i, 50) a[i] = -1;
    int nowpos = 0;

    while (true)
    {
        Pair p = getpair(nowpos);
        if (p.score != -1)
        {
            if (t < p.cost)
                break;
            t -= p.cost;
            int _;
            cout << p.a << endl;
            cin >> _;
            nowpos = p.a;
            cout << p.b << endl;
            cin >> _;
            nowpos = p.b;

            a[p.a] = -1;
            a[p.b] = -1;
        }
        else
        {
            int nextpos = nearest(nowpos);
            if (t < abs(nowpos - nextpos))
                break;
            t -= abs(nowpos - nextpos);
            cout << nextpos << endl;
            cin >> a[nextpos];
            nowpos = nextpos;
        }
    }
    cout << -1 << endl;
    return 0;
}
