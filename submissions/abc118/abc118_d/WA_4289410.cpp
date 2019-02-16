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

    cout << 124 << endl;
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

    /*rep(i, m)
    {
        for (int j = i; j < m; j++)
        {
            if (use[j].cost % use[i].cost == 0)
                use[j].cost = 1024;
        }
    }*/
    sort(use, use + m);

    Num p[m];
    rep(i, m) p[i] = {use[i].num, 0};
    while (n != 0)
    {
        rep(i, m)
        {

            //  cout << p[i].num << "," << n << endl;
            if (use[i].cost > n)
            {
                //  cout << "greater" << endl;
                int j = i;
                while (p[j].times == 0)
                    j--;
                p[j].times--;
                n += use[j].cost;
                i = j;
                continue;
            }
            p[i].times += n / use[i].cost;
            n = n % use[i].cost;
            if (n == 0)
                break;
        }
    }
    sort(p, p + m);
    rep(i, m)
    {
        rep(j, p[i].times) cout << p[i].num;
    }
    cout << endl;
    return 0;
}