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
pair<int, int> isWraped(Ball ball[], int n, int t)
{
    if (ball[t].x == -1)
        return {-1, -1};
    rep(i, n)
    {
        if (ball[i].x == -1 || i == t)
            continue;
        int d = distance(ball[i], ball[t]) - ball[i].r - ball[t].r;
        if (d < 0)
            return {i, -d};
    }
    return {-1, 1};
}
int main(int argc, char const *argv[])
{
    clock_t start = clock();
    random_device rnd;
    mt19937 mt(rnd());
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
        bonus[i].d += ball[bonus[i].a - 1].p + ball[bonus[i].b - 1].p;
    }

    sort(bonus, bonus + n, bonusCmp);
    map<int, bool> used;
    int x, y, z;
    x = y = z = 200;
    int cnt = 0;
    rep(i, m)
    {
        int a = bonus[i].a - 1, b = bonus[i].b - 1;

        if (used[a] == false && used[b] == false)
        {
            used[a] = true;
            used[b] = true;
            ball[a].x = 500 + ball[a].r;
            ball[a].y = 200 + ((cnt % 2 == 0) ? 400 : 0);
            ball[a].z = 200 + ((cnt >> 1 == 0) ? 400 : 0);

            ball[b].x = 500 - ball[b].r;
            ball[b].y = 200 + ((cnt % 2 == 0) ? 400 : 0);
            ball[b].z = 200 + ((cnt >> 1 == 0) ? 400 : 0);
            cnt += 1;
            dump(ball[a].x);
            dump(ball[a].y);
            dumpl(ball[a].z);

            dump(ball[b].x);
            dump(ball[b].y);
            dumpl(ball[b].z);
        }
        if (cnt == 4)
            break;
    }

    sort(ball, ball + n, cmpByScore);

    rep(i, n)
    {
        if ((double)(clock() - start) / CLOCKS_PER_SEC > 1900.0)
        {
            break;
        }
        if (used[ball[i].id])
            continue;
        ball[i].x = mt() % (n - ball[i].r);
        ball[i].y = mt() % (n - ball[i].r);
        ball[i].z = mt() % (n - ball[i].r);
        if (isWraped(ball, n, i).first != -1)
        {
            ball[i].x = -1;
            ball[i].y = -1;
            ball[i].z = -1;
        }
        else
        {
            cerr << i << endl;
        }
    }
    rep(i, n)
    {
        assert(isWraped(ball, n, i).first == -1);
    }
    sort(ball, ball + n, cmpById);
    rep(i, n)
    {
        cout << ball[i].x << " " << ball[i].y << " " << ball[i].z << endl;
    }
    return 0;
}
