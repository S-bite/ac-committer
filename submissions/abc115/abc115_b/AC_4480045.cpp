#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int p[n];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        ans += p[i];
    }
    sort(p, p + n);
    ans -= p[n - 1] / 2;
    cout << ans << endl;
    return 0;
}