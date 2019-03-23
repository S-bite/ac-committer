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
bool bonusCmp(const Bonus &a, const Bonus &b)
{
    return a.d > b.d;
}

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
    Ball ball[n];
    rep(i, n)
    {
        int r, p;
        cin >> r >> p;
        ball[i].id = i;
        ball[i].r = r;
        ball[i].p = p;
    }
    Bonus bonus[m];
    rep(i, m)
    {
        cin >> bonus[i].a >> bonus[i].b >> bonus[i].c >> bonus[i].d;
    }

    sort(bonus, bonus + n, bonusCmp);
    map<int, bool> used;
    int x, y, z;
    x = y = z = 200;
    int cnt = 0;
    rep(i, m)
    {
        int a = bonus[i].a, b = bonus[i].b;

        if (used[a] == false && used[b] == false)
        {
            used[a] = true;
            used[b] = true;
            ball[a].x = 500 + ball[a].r;
            ball[a].y = 200 + (cnt % 2 == 0) ? 400 : 0;
            ball[a].z = 200 + (cnt % 4 == 0) ? 400 : 0;

            ball[b].x = 500 + ball[b].r;
            ball[b].y = 200 + (cnt % 2 == 0) ? 400 : 0;
            ball[b].z = 200 + (cnt % 4 == 0) ? 400 : 0;
            cnt += 2;
        }
        if (cnt == 8)
            break;
    }

    //sort(ball, ball + n, cmpById);
    rep(i, n)
    {
        cout << ball[i].x << " " << ball[i].y << " " << ball[i].z << endl;
    }
    return 0;
}
