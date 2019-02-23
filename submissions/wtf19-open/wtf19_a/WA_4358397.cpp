#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int main()
{
    int n, k, sum = 0, mn = 101;
    cin >> n >> k;
    int a[n];
    rep(i, n)
    {
        cin >> a[i];
        sum += a[i];
        mn = min(mn, a[i]);
    }
    if (mn > k)
    {
        cout << k + 1 << endl;
        rep(i, k + 1)
        {
            rep(j, n)
            {
                cout << j + 1 << " ";
            }
        }
        cout << endl;
        return 0;
    }
    //if (2 * mn <= k)
    {
        cout << -1 << endl;
    }

    return 0;
}