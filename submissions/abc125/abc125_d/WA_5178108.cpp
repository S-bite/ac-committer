#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a < b)
    {
        int t = a;
        a = b;
        b = t;
    }
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

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
    for (int i = 0; i < (n + 1) / 2; i += 2)
    {
        if (a[i] < 0 && (a[i + 1] < 0 || -(a[i] + a[i + 1]) > 0))
        {
            a[i] *= -1;
            a[i + 1] *= -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}