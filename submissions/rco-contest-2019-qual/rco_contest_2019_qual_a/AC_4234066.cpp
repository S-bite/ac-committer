#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define fir first
#define sec second
#define N 200
using namespace std;

double eval(int order[N], pair<int, int> pos[N])
{
    double mcost = 0;
    ll dist[N];
    rep(i, N)
    {
        ll dx = pos[order[i]].fir - pos[order[(i + 1) % N]].fir;
        ll dy = pos[order[i]].sec - pos[order[(i + 1) % N]].sec;

        dist[i] = sqrt(dx * dx + dy * dy);
        mcost += dist[i];
    }
    mcost /= N;
    double ret = 0.0;
    rep(i, N)
    {
        ret += (dist[i] - mcost) * (dist[i] - mcost);
    }
    return -ret;
}

int main()
{
    int n;
    cin >> n;

    pair<int, int> p[n];
    rep(i, n) cin >> p[i].fir >> p[i].sec;
    int dis[n][n];
    rep(i, n) for (int j = i + 1; j < n; j++)
    {
        dis[i][j] = (p[i].fir - p[j].fir) * (p[i].fir - p[j].fir) + (p[i].sec - p[j].sec) * (p[i].sec - p[j].sec);
        dis[j][i] = dis[i][j];
    }
    ll mcost = 0;
    rep(i, n) rep(j, n)
    {
        mcost += (ll)dis[i][j];
    }
    mcost /= n * n;
    map<int, bool> mp;
    int order[n];
    order[0] = 0;
    mp[0] = true;
    int now = 0;
    rep(i, n - 1)
    {
        ll diff = 1ll << 30;
        int next;
        rep(j, n)
        {
            if (mp[j] == true)
            {
                continue;
            }
            if (abs(dis[now][j] - mcost) < diff)
            {
                diff = abs(dis[now][j] - mcost);
                next = j;
            }
        }
        order[i + 1] = next;
        mp[next] = true;
        now = next;
    }
    //  rep(i, n) order[i] = i;
    clock_t start = clock();
    int count = 0;
    double score = eval(order, p);
    while ((double)(clock() - start) / CLOCKS_PER_SEC * 1000.0 < 1900.0)
    {
        int _order[n];
        rep(i, n) _order[i] = order[i];
        int num;
        double nowtime = (double)(clock() - start) / CLOCKS_PER_SEC * 1000.0;
        if (nowtime <= 500)
        {
            num = 1000;
        }
        else if (nowtime <= 1200)
        {
            num = 100;
        }
        else
            num = 10;

        rep(i, 1) //(int)(1000 - 500 * (double)(clock() - start) / CLOCKS_PER_SEC))
        {
            int r1 = random() % n;
            int r2 = random() % n;
            //cout << "r1:" << r1 << " r2:" << r2 << endl;
            int tmp = order[r1];
            order[r1] = order[r2];
            order[r2] = tmp;
        }
        double escore = eval(order, p);
        //  cout << "escore:" << escore << endl;
        if (escore > score)
        {
            // cout << "update!" << endl;
            score = escore;
        }
        else
        {
            rep(i, n) order[i] = _order[i];
        }
        count++;
    }
    rep(i, n)
    {
        cout << order[i] << endl;
    }
    //cout << count << endl;
    return 0;
}
