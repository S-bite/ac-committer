#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    pair<int, int> p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n);
    int ans = -1;
    int i = 0;
    while (k > 0)
    {
        ans = p[i].first;
        k -= p[i].second;
        i++;
    }
    cout << ans << endl;
    return 0;
}
