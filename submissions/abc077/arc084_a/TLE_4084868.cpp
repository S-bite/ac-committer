#include <bits/stdc++.h>
#define vec vector
#define ALL(v) v.begin(), v.end()
#define ll long long
using namespace std;
int main()
{
    int n;
    cin >> n;
    vec<int> a, b, c;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        b.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        c.push_back(t);
    }
    sort(ALL(a));
    sort(ALL(b));
    sort(ALL(c));
    ll ans = 0;
    for (auto i : a)
    {

        auto j = upper_bound(ALL(b), i);
        if (j == b.end())
            break;
        for (; j != b.end(); j++)
        {

            auto k = upper_bound(ALL(c), *j);

            //cout << *j << "," << c.end() - k << endl;
            ans += c.end() - k;
            if (c.end() - k == 0)
                break;
        }
    }
    cout << ans << endl;
    return 0;
}