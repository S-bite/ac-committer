#include <bits/stdc++.h>
using namespace std;

long long calc(long long s[100000], int n, bool f)
{
    long long cng = 0;
    long long ans = 0;
    if (f)
    {
        //最初を正の数にする
        if (s[0] <= 0)
        {
            cng = abs(s[0]) + 1;
            ans += cng;
        }
    }
    else
    {
        //最初を負の数にする
        if (s[0] >= 0)
        {
            cng = -abs(s[0]) - 1;
            ans += -cng;
        }
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
    return ans;
}

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
    cout << min(calc(s, n, true), calc(s, n, false)) << endl;
    return 0;
}