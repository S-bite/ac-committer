#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    int ans = 1000;
    while (k != 0)
    {
        ans--;
        if (a % ans == 0 && b % ans == 0)
        {
            k--;
            //     cout << ans << endl;
        }
    }
    cout << ans << endl;

    return 0;
}