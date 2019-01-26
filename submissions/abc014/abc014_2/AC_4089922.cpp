#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k, ans = 0;
    cin >> n >> k;
    while (k)
    {
        int t;
        cin >> t;
        if (k & 1 == 1)
            ans += t;
        k >>= 1;
    }
    cout << ans << endl;
}