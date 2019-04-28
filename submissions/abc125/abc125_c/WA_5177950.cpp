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
    int rgcd[n + 2], lgcd[n + 2], a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 2)
    {
        cout << max(a[0], a[1]) << endl;
        return 0;
    }
    lgcd[0] = 0;
    lgcd[1] = a[0];
    lgcd[n + 1] = 0;

    rgcd[0] = 0;
    rgcd[n] = a[n - 1];
    rgcd[n + 1] = 0;

    for (int i = 2; i < n + 1; i++)
    {
        lgcd[i] = gcd(lgcd[i - 1], a[i - 2]);
    }
    for (int i = n - 1; i >= 1; i--)
    {
        rgcd[i] = gcd(rgcd[i + 1], a[i - 1]);
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, gcd(rgcd[i + 1], lgcd[i - 1]));
    }
    cout << ans << endl;
    return 0;
}