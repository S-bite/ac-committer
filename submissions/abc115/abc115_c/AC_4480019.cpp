#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    long long a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    long long ans = 1ll << 60;
    for (int i = 0; i < n - k + 1; i++)
    {
        //cout << a[i + k - 1] << "," << a[i] << endl;
        ans = min(ans, a[i + k - 1] - a[i]);
    }
    cout << ans << endl;
    return 0;
}