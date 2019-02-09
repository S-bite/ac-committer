#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main()
{
    int k, a, b;
    cin >> k >> a >> b;
    if (b - a <= 2)
    {
        cout << k + 1 << endl;
        return 0;
    }
    if (1 + k - 2 < a)
    {
        cout << k + 1 << endl;
        return 0;
    }
    ll t = a - 1;
    cout << a + ((k - t) / 2) * (b - a) + ((k - t) % 2) << endl;

    return 0;
}