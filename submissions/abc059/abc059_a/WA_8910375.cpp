#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n], s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
        {
            s[0] = a[0];
        }
        else
        {
            s[i] = s[i - 1] + a[i];
        }
    }
    long long cng = 0;
    long long ans = 0;

    if (a[0] == 0)
    {
        if (0 > a[1])
        {
            cng--;
        }
        else
        {
            cng++;
        }
        ans++;
    }
    for (int i = 1; i < n; i++)
    {
        if (((s[i] + cng < 0) && (0 < s[i - 1] + cng)) || ((s[i] + cng > 0) && (0 > s[i - 1] + cng)))
        {
            //ok
            continue;
        }
        assert(s[i - 1] + cng != 0);

        if (s[i] + cng >= 0) //減らさないといけない
        {
            ans += s[i] + cng + 1;

            cng -= s[i] + cng + 1;
        }
        else //増やさないといけない
        {
            ans += -(s[i] + cng) + 1;

            cng += -(s[i] + cng) + 1;
        }
    }
    cout << ans << endl;
    return 0;
}