#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ll long long
using namespace std;
int main()
{
    map<int, ll> mp;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int t = i, p = 2;
        while (t != 1)
        {
            if (t % p == 0)
            {
                mp[p]++;
                t /= p;
                continue;
            }
            p++;
        }
    }
    int ans = 0;
    for (int i = 0; i <= n - 3; i++)
        for (int j = i + 1; j <= n - 2; j++)
            for (int k = j + 1; k <= n - 1; k++)
            {
                int a = mp[i];
                int b = mp[j];
                int c = mp[k];
                int l[] = {a, b, c};
                if (l[0] >= 2 and l[1] >= 4 and l[2] >= 4)
                    ans++;
                if (l[1] >= 2 and l[2] >= 4 and l[0] >= 4)
                    ans++;
                if (l[2] >= 2 and l[0] >= 4 and l[1] >= 4)
                    ans++;
                //if (l[0] >= 2 and l[2] >= 4 and l[1] >= 4)
                //    ans++;
                // if (l[2] >= 2 and l[1] >= 4 and l[0] >= 4)
                //ans++;
                //if (l[1] >= 2 and l[0] >= 4 and l[2] >= 4)
                //ans++;
            }
    for (int i = 0; i <= n - 2; i++)
        for (int j = i + 1; j <= n - 1; j++)
        {
            int a = mp[i];
            int b = mp[j];
            int l[] = {a, b};
            if (l[0] >= 24 and l[1] >= 2)
                ans++;
            if (l[0] >= 14 and l[1] >= 4)
                ans++;
            if (l[1] >= 24 and l[0] >= 2)
                ans++;
            if (l[1] >= 14 and l[0] >= 4)
                ans++;
        }
    for (int i = 0; i <= n - 1; i++)
    {
        int a = mp[i];
        if (a >= 74)
            ans++;
    }
    cout << ans << endl;
    return 0;
}