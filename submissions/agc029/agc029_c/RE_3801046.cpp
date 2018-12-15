#include <bits/stdc++.h>
#include <math.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
bool is_ok(int a[], int n, int m, int p)
{
    //cout << "p:" << p << endl;
    int o[m];
    rep(i, m) o[i] = 0;
    for (ll i = 1; i < n; i++)
    {
        //rep(i, m) cout << o[i];
        //cout << endl;

        for (ll j = 0; j < m - a[i]; j++)
            o[j] = 0;
        o[m - a[i]]++;
        for (ll j = m - a[i]; j < m - 1; j++)
            if (o[j] > p - 1)
            {
                o[j] = 0;
                o[j + 1]++;
            }
        if (o[m - 1] > p - 1)
            return false;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    int a[n], m = -1;
    rep(i, n)
    {
        int t;
        cin >> t;
        a[i] = t;
        m = max(m, a[i]);
    }
    int ans = 1;
    int l = 0, h = n;
    while (l + 1 != h)
    {
        ans = (l + h) / 2;
        if (is_ok(a, n, m, ans))
            h = ans;
        else
            l = ans;
    }

    cout << h << endl;
    return 0;
}