#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ll long long
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    rep(i, n) cin >> a[i];
    sort(a, a + n);
    int ans = a[n - 1];
    rep(i, n - k + 1)
    {
        ans = min(ans, a[i + k - 1] - a[i]);
    }
    cout << ans << endl;
    return 0;
}