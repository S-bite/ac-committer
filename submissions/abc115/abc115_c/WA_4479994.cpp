#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int ans = 1 << 20;
    for (int i = 0; i < n - k; i++)
    {
        //cout << a[i + k] << "," << a[i] << endl;
        ans = min(ans, a[i + k - 1] - a[i]);
    }
    cout << ans << endl;
    return 0;
}