#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ll long long
using namespace std;
int main()
{
    int n, s = 0, m = -1;
    cin >> n;
    rep(i, n)
    {
        int t;
        cin >> t;
        m = max(m, t);
        s += t;
    }
    cout << (s - m / 2) << endl;
    return 0;
}