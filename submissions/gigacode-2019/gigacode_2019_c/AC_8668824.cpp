#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    long long cur = 0;
    long long ans = (1ll << 60);
    for (int i = 0; i < n; i++)
    {
        cur += a[i];
        if (b[i] <= cur)
        {
            ans = min(ans, b[i]);
        }
    }
    if (ans == (1ll << 60))
        ans = -1;
    cout << ans << endl;
    return 0;
}