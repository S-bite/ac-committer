#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;

int main()
{
    int n;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    int ans = 0;
    bool isend = false;
    while (isend == false)
    {
        isend = true;
        for (int i = 0; i < n; i++)
        {
            if (h[i] > 0)
            {
                ans++;
                isend = false;
                for (int j = i; j < n; j++)
                {
                    if (h[j] == 0)
                        break;
                    h[j]--;
                }
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}