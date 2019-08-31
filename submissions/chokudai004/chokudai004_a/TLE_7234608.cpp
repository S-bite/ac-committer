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
//最初は貪欲！！！！！
int n;
int b[3];
mt19937 mt(0);

ll eval_y(vector<vector<int>> &v, int y) //y列目のスコアを計算
{
    int sum = 0;
    int ret = 0;
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    rep(i, n)
    {
        rep(j, i, n)
        {
            sum += v[y][j];
            if (sum == b[0])
            {
                n1++;
            }
            else if (sum == b[1])
            {
                n2++;
            }
            else if (sum == b[2])
            {
                n3++;
            }
        }
        sum = 0;
    }
    return n1 * b[0] + n2 * b[1] + n3 * b[2];
}
ll eval_x(vector<vector<int>> &v, int x) //x行目のスコアを計算
{
    int sum = 0;
    int ret = 0;
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    rep(i, n)
    {
        rep(j, i, n)
        {
            sum += v[j][x];
            if (sum == b[0])
            {
                n1++;
            }
            else if (sum == b[1])
            {
                n2++;
            }
            else if (sum == b[2])
            {
                n3++;
            }
        }
        sum = 0;
    }
    return n1 * b[0] + n2 * b[1] + n3 * b[2];
}

ll eval(vector<vector<int>> &v) //スコアを計算
{
    ll ret = 0;
    rep(i, n)
    {
        ret += eval_x(v, i);
        ret += eval_y(v, i);
    }
    return ret;
}
ll evals(vector<vector<int>> &v, int y, int x)
{
    ll ret = 0;
    ret += eval_x(v, x);
    ret += eval_y(v, y);
    return ret;
}

void show(vector<vector<int>> &v)
{
    rep(i, n)
    {
        rep(j, n)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

unsigned long xor128()
{
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t;
    t = (x ^ (x << 11));
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}
//[0,1)の一様乱数
// 注意: int_maxぐらいで割るべき
double frand()
{
    return xor128() % ULONG_MAX / static_cast<double>(ULONG_MAX);
}

int main(int argc, char const *argv[])
{
    clock_t starttime = clock();
    cin >> n;
    cin >> b[0] >> b[1] >> b[2];
    vector<vector<int>> l(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> l[i][j];
    vector<vector<int>> r(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> r[i][j];
    vector<vector<int>> ans(n, vector<int>(n));

    rep(i, n)
    {
        rep(j, n)
        {
            ans[i][j] = l[i][j];
        }
    }
    ll bestscore = eval(ans);
    cerr << bestscore << endl;

    auto best = ans;
    ll nowscore = bestscore;
    int cnt = 0;
    double C = 3.0 * CLOCKS_PER_SEC * 1000;
    while (double(clock() - starttime) / CLOCKS_PER_SEC < 3.0) //
    {

        cnt++;
        int y = mt() % n;
        int x = mt() % n;

        //if (swappable(ans, l, r, y, x1, x1 + 1))
        //{
        //   swap(ans, y, x1, x1 + 1);
        //}
        nowscore -= evals(ans, y, x);
        ans[y][x] = mt() % (r[y][x] - l[y][x] + 1) + l[y][x];
        nowscore += evals(ans, y, x);
        double delta = bestscore - nowscore;
        //T = double(clock() - c) / CLOCKS_PER_SEC;
        double force = (clock() - starttime) / C;
        if (delta < 0.0 || force > frand())
        {
            //cerr << "update " << eval(ans) << "," << eval(best) << endl;
            best = ans;
            bestscore = nowscore;
        }
        //else if (exp(-delta / T) > frand())
        // {
        //}
        else
        {
            ans = best;
            nowscore = bestscore;
        }
    }

    show(best);
    cerr << eval(best) << "," << cnt << endl;

    return 0;
}
