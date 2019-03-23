#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
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

struct Ball
{
    int id, r, p;
    int x = -1, y = -1, z = -1;
};

struct Bonus
{
    int a, b, c, d;
};

bool cmpByScore(const Ball &a, const Ball &b)
{
    return a.p > b.p;
}
bool cmpById(const Ball &a, const Ball &b)
{
    return a.id < b.id;
}

double distance(Ball a, Ball b)
{
    return sqrt((double)(a.x - b.x) * (a.x - b.x) + (double)(a.y - b.y) * (a.y - b.y) + (double)(a.z - b.z) * (a.z - b.z));
}
int wrapDistance(Ball ball[], int n, int t)
{
    rep(i, n)
    {
        if (ball[i].x == -1)
            continue;
        int d = distance(ball[i], ball[t]) - ball[i].r + ball[t].r;
        if (d < 0)
            return -d;
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int l, m, n;
    cin >> l >> n >> m;
    cerr << l << "," << m << "," << n << "," << endl;
    Ball ball[n];
    rep(i, n)
    {
        int r, p;
        cin >> r >> p;
        ball[i].id = i;
        ball[i].r = r;
        ball[i].p = p;
        cerr << ball[i].r << endl;
    }
    sort(ball, ball + n, cmpByScore);
    Bonus bonus[m];
    rep(i, m)
    {
        cin >> bonus[i].a >> bonus[i].b >> bonus[i].c >> bonus[i].d;
    }

    int x, y, z;
    x = y = z = 200;
    rep(i, 8)
    {
        dump(x);
        dump(y);
        dump(z);
        dumpl(ball[i].r);
        ball[i].x = x;
        ball[i].y = y;
        ball[i].z = z;
        x += 400;
        if (x == 1000)
        {
            x = 200;
            y += 400;
        }
        if (y == 1000)
        {
            y = 200;
            x = 200;
            z += 400;
        }
    }
    sort(ball, ball + n, cmpById);
    rep(i, n)
    {
        cout << ball[i].x << " " << ball[i].y << " " << ball[i].z << endl;
    }
    return 0;
}
