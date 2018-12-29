#include <bits/stdc++.h>
#include <math.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    if (c <= (a + b))
        cout << (b + c) << endl;
    else
        cout << (a + b + b + 1) << endl;

    return 0;
}
