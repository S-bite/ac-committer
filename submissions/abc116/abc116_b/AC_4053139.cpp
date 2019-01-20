#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;

int main()
{
    int s;
    map<int, bool> mp;
    cin >> s;
    mp[s] = true;
    int ans = 1;
    do
    {
        if (s % 2 == 0)
            s /= 2;
        else
            s = 3 * s + 1;
        ans++;
        if (mp[s] == true)
            break;
        mp[s] = true;

    } while (true);
    cout << ans << endl;
    return 0;
}