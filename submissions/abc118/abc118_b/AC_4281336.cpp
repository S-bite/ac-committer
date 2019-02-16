#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    rep(i, n)
    {
        int k;
        cin >> k;
        rep(j, k)
        {
            int t;
            cin >> t;
            mp[t]++;
        }
    }
    int ans = 0;
    rep(i, m + 1)
    {
        if (mp[i] == n)
            ans++;
    }
    cout << ans << endl;
    return 0;
}