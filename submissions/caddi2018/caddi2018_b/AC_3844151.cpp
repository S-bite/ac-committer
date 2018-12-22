#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define fir first
#define sec second
using namespace std;
int main()
{
    ll n;
    cin >> n;
    bool win = false;
    rep(i, n)
    {
        ll t;
        cin >> t;
        if (t % 2 == 1)
            win = true;
    }
    if (win)
        cout << "first" << endl;
    else
        cout << "second" << endl;
    return 0;
}
