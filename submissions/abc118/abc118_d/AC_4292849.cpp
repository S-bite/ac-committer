#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define INF (1 << 20)
using namespace std;
int main()
{
    int cost[10] = {8,
                    2,
                    5,
                    5,
                    4,
                    5,
                    6,
                    3,
                    7,
                    6};
    int n, m;
    cin >> n >> m;
    int use[m];

    rep(i, m) cin >> use[i];
    sort(use, use + m, greater<int>());
    int dp[n];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -INF;
        rep(j, m)
        {
            if (i - cost[use[j]] >= 0)
            {
                dp[i] = max(dp[i], dp[i - cost[use[j]]] + 1);
            }
        }
    }
    int N = n;
    rep(i, dp[n])
    {
        int ans = -1;
        rep(j, m)
        {

            if ((N - cost[use[j]] >= 0) && (dp[N - cost[use[j]]] == dp[N] - 1))
            {

                ans = use[j];
                N -= cost[use[j]];
                break;
            }
        }
        cout << ans;
        }
    cout << endl;
    return 0;
}