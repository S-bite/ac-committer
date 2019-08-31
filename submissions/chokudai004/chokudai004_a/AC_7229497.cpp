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

int eval_y(vector<vector<int>> &v, int y) //y列目のスコアを計算
{
    int sum = 0;
    int ret = 0;
    rep(i, n)
    {
        rep(j, i, n)
        {
            sum += v[y][j];
            if (sum == b[0])
            {
                ret += (j - i + 1) * b[0];
            }
            else if (sum == b[1])
            {
                ret += (j - i + 1) * b[1];
            }
            else if (sum == b[2])
            {
                ret += (j - i + 1) * b[2];
            }
        }
        sum -= v[y][i];
    }
    return ret;
}
int eval_x(vector<vector<int>> &v, int x) //x行目のスコアを計算
{
    int sum = 0;
    int ret = 0;
    rep(i, n)
    {
        rep(j, i, n)
        {
            sum += v[j][x];
            if (sum == b[0])
            {
                ret += (j - i + 1) * b[0];
            }
            else if (sum == b[1])
            {
                ret += (j - i + 1) * b[1];
            }
            else if (sum == b[2])
            {
                ret += (j - i + 1) * b[2];
            }
        }
        sum -= v[i][x];
    }
    return ret;
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

//v[y][x]とv[y][x+1]が交換可能か？
bool swappable(vector<vector<int>> &v, vector<vector<int>> &l, vector<vector<int>> &r, int y, int x1, int x2)
{
    return (l[y][x1] <= v[y][x2] && v[y][x2] <= r[y][x1] && l[y][x2] <= v[y][x1] && v[y][x1] <= r[y][x2]);
}
void swap(vector<vector<int>> &v, int y, int x1, int x2)
{
    int tmp = v[y][x1];
    v[y][x1] = v[y][x2];
    v[y][x2] = tmp;
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

int main(int argc, char const *argv[])
{
    clock_t c = clock();
    cin >> n;
    cin >> b[0] >> b[1] >> b[2];
    vector<vector<int>> l(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> l[i][j];
    vector<vector<int>> r(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> r[i][j];
    vector<vector<int>> ans(n, vector<int>(n));
    int cur = b[2];

    rep(i, n)
    {
        rep(j, n)
        {
            if (cur > l[i][j] + 1)
            {
                ans[i][j] = l[i][j];
                cur -= l[i][j];
            }
            else
            {
                ans[i][j] = l[i][j];
                cur = b[2];
            }
            ans[i][j] = (l[i][j] + r[i][j]) / 2;
        }
        cur = b[2];
    }
    cerr << eval(ans) << endl;

    auto copy = ans;
    int cnt = 0;
    while (double(clock() - c) / CLOCKS_PER_SEC < 2.9)
    {
        int y = mt() % n;
        int x1 = mt() % (n + 1);
        int x2 = mt() % (n + 1);

        if (swappable(ans, l, r, y, x1, x2))
        {
            swap(ans, y, x1, x2);
            cnt++;
        }
        /* else if (ans[y][x] > l[y][x] && mt() % 10 == 0)
        {
            ans[y][x]--;
        }
        else if (ans[y][x] < r[y][x] && mt() % 10 == 0)
        {
            ans[y][x]++;
        }*/
        if (cnt % 10 == 0)
        {
            if (eval(ans) > eval(copy))
            {
                cerr << "update" << endl;
                copy = ans;
            }
        }
    }
    show(ans);
    cerr << eval(copy) << "," << cnt << endl;

    return 0;
}
