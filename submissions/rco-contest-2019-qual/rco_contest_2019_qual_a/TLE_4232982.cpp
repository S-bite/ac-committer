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
        ll dx = pos[i].fir - pos[(i + 1) % N].fir;
        ll dy = pos[i].sec - pos[(i + 1) % N].sec;
        dist[i] = dx * dx + dy * dy;
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
    clock_t start = clock();
    int count = 0;
    double score = eval(order, p);
    while ((clock() - start) / CLOCKS_PER_SEC * 1000.0 < 1600.0)
    {
        int _order[n];
        rep(i, n) _order[i] = order[i];
        int r1 = random() % n;
        int r2 = random() % n;
        order[r1] = _order[r2];
        order[r2] = _order[r1];
        double escore = eval(order, p);
        if (escore > score)
        {
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