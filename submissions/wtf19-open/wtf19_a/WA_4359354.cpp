#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int main()
{
    int n, k, sum = 0, mn = 101, mnind = -1;

    cin >> n >> k;
    int a[n];
    rep(i, n)
    {
        cin >> a[i];
        sum += a[i];
        if (a[i] < mn)
        {
            mn = a[i];
            mnind = i + 1;
        }
    }
    if (2 * mn >= k)
    {
        cout << max((k + 1) / 2, 1) * (n) + n - 1 << endl;
        rep(i, max((k + 1) / 2, 1))
        {
            rep(j, n)
            {
                if (j + 1 == mnind)
                    continue;
                cout << j + 1 << " ";
            }
            cout << mnind << " ";
        }
        rep(j, n)
        {
            if (j + 1 == mnind)
                continue;
            cout << j + 1 << " ";
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