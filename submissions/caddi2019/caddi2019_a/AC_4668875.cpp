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
    return sqrt((double)(a.x - b.x) * (double)(a.x - b.x) + (double)(a.y - b.y) * (double)(a.y - b.y) + (double)(a.z - b.z) * (double)(a.z - b.z));
}
pair<int, int> isWraped(Ball ball[], int n, int t)
{

    if (ball[t].x == -1)
        return {-1, -1};

#define check(a, b)                \
    if (a + b > 1000 || a - b < 0) \
        return {0, 0};
    check(ball[t].x, ball[t].r);
    check(ball[t].y, ball[t].r);
    check(ball[t].z, ball[t].r);
    double minDist = 1000 * 1000;
    rep(i, n)
    {
        if (ball[i].x == -1 || i == t)
            continue;

        double d = distance(ball[i], ball[t]) - ball[i].r - ball[t].r;
        //cerr << ":" << i << "," << t << "," << distance(ball[i], ball[t]) << "," << ball[i].r << "," << ball[t].r << "," << d << endl;

        if (d < 0)
            return {i, -d};
        minDist = min(minDist, d);
    }
    return {-1, minDist};
}
void show(Ball b)
{
    cerr << b.id << "," << b.x << "," << b.y << "," << b.z << "," << b.r << endl;
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
    rep(cnt, 4)
    {
        int i = cnt;

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
            sort(ball, ball + n, cmpById);

            dump(ball[b].x);
            dump(ball[b].y);
            dumpl(ball[b].z);
        }
    }

    sort(ball, ball + n, cmpByScore);

    int cc = 0;
    rep(k, m)
    {
        if (((double)(clock() - start) / CLOCKS_PER_SEC > 2.9))
            break;
        int i = bonus[k].a - 1;
        int j = bonus[k].b - 1;
        if (used[ball[i].id])
            continue;

        int bx, by, bz;
        bx = by = bz = -1;
        double bestDist = 1000 * 1000;
        rep(_, 10)
        {

            ball[i].x = mt() % (n - 2 * ball[i].r - 2) + ball[i].r;
            ball[i].y = mt() % (n - 2 * ball[i].r - 2) + ball[i].r;
            ball[i].z = mt() % (n - 2 * ball[i].r - 2) + ball[i].r;
            auto ret = isWraped(ball, n, i);
            if (ret.first == -1)
            {
                if (bestDist > ret.second)
                {
                    bestDist = ret.second;
                    bx = ball[i].x;
                    by = ball[i].y;
                    bz = ball[i].z;
                    //cerr << "***" << i << endl;
                }
                //show(ball[i]);
            }
        }
        ball[i].x = bx;
        ball[i].y = by;
        ball[i].z = bz;
        if (bx != -1)
        {
            used[ball[i].id] = true;
            cc++;
        }
        else
            continue;

        //////
        if (used[ball[j].id])
            continue;

        bx = by = bz = -1;
        bestDist = 1000 * 1000;
        rep(_, 10)
        {

            ball[j].x = mt() % (n - 2 * ball[j].r - 2) + ball[j].r;
            ball[j].y = mt() % (n - 2 * ball[j].r - 2) + ball[j].r;
            ball[j].z = mt() % (n - 2 * ball[j].r - 2) + ball[j].r;
            auto ret = isWraped(ball, n, j);
            ret.second = distance(ball[i], ball[j]);
            if (ret.first == -1)
            {
                if (bestDist > ret.second)
                {
                    bestDist = ret.second;
                    bx = ball[j].x;
                    by = ball[j].y;
                    bz = ball[j].z;
                    // cerr << "***" << j << endl;
                }
                //show(ball[i]);
            }
        }
        ball[j].x = bx;
        ball[j].y = by;
        ball[j].z = bz;
        if (bx != -1)
        {
            used[ball[j].id] = true;
            cc++;
        }
    }

    rep(i, n)
    {

        if (used[ball[i].id])
            continue;
        int bx, by, bz;
        bx = by = bz = -1;
        double bestDist = 1000 * 1000;
        rep(j, 1500)
        {

            ball[i].x = mt() % (n - 2 * ball[i].r - 2) + ball[i].r;
            ball[i].y = mt() % (n - 2 * ball[i].r - 2) + ball[i].r;
            ball[i].z = mt() % (n - 2 * ball[i].r - 2) + ball[i].r;
            auto ret = isWraped(ball, n, i);
            if (ret.first == -1)
            {
                if (bestDist > ret.second)
                {
                    bestDist = ret.second;
                    bx = ball[i].x;
                    by = ball[i].y;
                    bz = ball[i].z;
                    cerr << "***" << i << endl;
                }
                //show(ball[i]);
            }
        }
        ball[i].x = bx;
        ball[i].y = by;
        ball[i].z = bz;
    }
    cerr << cc << endl;
    sort(ball, ball + n, cmpById);

    rep(i, n)
    {

        //   show(ball[i]);
        assert(isWraped(ball, n, i).first == -1);
    }
    rep(i, n)
    {
        cout << ball[i].x << " " << ball[i].y << " " << ball[i].z << endl;
    }
    return 0;
}
