#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ll long long
#define ALL(x) x.begin(), x.end()
#define fir first
#define sec second
using namespace std;

int main()
{
    double ans = 0;
    int n;
    cin >> n;
    rep(i, n)
    {
        double t;
        string s;
        cin >> t >> s;
        if (s == "JPY")
            ans += t;
        else
            ans += 380000.0 * t;
    }
    cout << ans << endl;
    return 0;
}