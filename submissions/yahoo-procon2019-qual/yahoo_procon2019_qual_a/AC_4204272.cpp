#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for ((ll)i = 0; i < (n); i++)
using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;
    if (2 * k - 1 <= n)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}