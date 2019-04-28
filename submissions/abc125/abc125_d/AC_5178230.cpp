#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (-(a[i] + a[i + 1]) > 0)
        {
            a[i] *= -1;
            a[i + 1] *= -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cerr << a[i] << endl;
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}