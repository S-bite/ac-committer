#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int main()
{
    string s;
    cin >> s;
    int ans = 0;
    bool f = true;
    while (f)
    {
        f = false;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] != s[i + 1] && s[i] != '@')
            {
                f = true;
                ans += 2;
                s[i] = '@';
                s[i + 1] = '@';
            }
        }
        string t = "";
        rep(i, s.size())
        {
            if (s[i] != '@')
                t += s[i];
        }
        s = t;
        //  cout << s << endl;
    }
    cout << ans << endl;
    return 0;
}