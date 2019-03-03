#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int main()
{
    string s;
    cin >> s;
    int zero = 0, one = 0;
    rep(i, s.size())
    {
        if (s[i] == '1')
            one++;
        else
            zero++;
    }
    cout << 2 * min(one, zero) << endl;
    return 0;
}