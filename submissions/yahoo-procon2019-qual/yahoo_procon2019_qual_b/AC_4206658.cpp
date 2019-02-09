#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main()
{
    int p[4] = {0, 0, 0, 0};
    rep(i, 3)
    {
        int a, b;
        cin >> a >> b;
        p[a - 1]++;
        p[b - 1]++;
    }
    rep(i, 4)
    {
        if (p[i] == 3)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}