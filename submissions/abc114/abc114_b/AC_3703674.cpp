#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int main()
{
    string s;
    int ret = 10000000;
    cin >> s;
    rep(i, s.size() - 2)
    {
        int t = atoi(s.substr(i, 3).c_str()); //)strcat(s[i], s[i + 1], s[i + 2]);
        ret = min(ret, abs(753 - t));
    }
    cout << ret << endl;
    return 0;
}