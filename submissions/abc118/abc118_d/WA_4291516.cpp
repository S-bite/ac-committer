#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
struct Match
{
    int num;
    int cost;
    bool operator<(const Match &another) const
    {
        return cost < another.cost;
    };
};
struct Num
{
    int num;
    int times;
    bool operator<(const Num &another) const
    {
        return num > another.num;
    };
};

Match all[9] = {
    {1, 2},
    {2, 5},
    {3, 5},
    {4, 4},
    {5, 5},
    {6, 6},
    {7, 3},
    {8, 7},
    {9, 6},
};
int main()
{

    int n, m;
    cin >> n >> m;
    Match use[m];
    rep(i, m)
    {
        int t;
        cin >> t;
        use[i] = all[t - 1];
    }
    sort(use, use + m);

    /* rep(i, m)
    {
        for (int j = i + 1; j < m; j++)
        {
            if ((use[j].cost % use[i].cost) == 0)
                use[j].cost = 1024;
        }
    }*/
    sort(use, use + m);

    Num p[m], q[m];
    rep(i, m) q[i] = p[i] = {use[i].num, 0};
    sort(q, q + m);
    p[0].times = n / use[0].cost;
    int _n = n;
    n = n % use[0].cost;

    while (n != 0)
    {
        rep(i, m)
        {
            if (q[i].num == p[0].num)
                continue;
            if (all[q[i].num - 1].cost <= n)
            {
                n -= all[q[i].num - 1].cost;
                q[i].times++;
            }
            else
            {
                n = _n;
                p[0].times--;
                n = n - p[0].times * use[0].cost;
                rep(j, m) q[j].times = 0;
                i = -1;
                continue;
            }
            if (n == 0)
                break;
        }
    }
    sort(p, p + m);
    rep(i, m)
    {
        rep(j, p[i].times + q[i].times) cout << p[i].num;
    }
    cout << endl;
    return 0;
}