#include <bits/stdc++.h>
#include <math.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;

bool is_ok(int a[], int n, int m, int p)
{

    //cout << "p:" << p << endl;
    vector<int> o(m);
    o.push_back(0);
    for (ll i = 1; i < n; i++)
    {

        int s = o.size();
        //rep(i, s) cout << o[i] << " ";
        //cout << endl;
        if (s < a[i])
        {
            rep(j, s) o[i] = 0;
            rep(j, a[i] - s) o.push_back(0);
        }
        s = o.size();
        o[a[i] - 1]++;
        for (ll j = a[i] - 1; j < s - 1; j++)
            if (o[j] > p - 1)
            {
                o[j] = 0;
                o[j + 1]++;
            }
        if (o[s - 1] > p - 1)
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