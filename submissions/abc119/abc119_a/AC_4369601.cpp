#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ll long long
#define ALL(x) x.begin(), x.end()
#define fir first
#define sec second
using namespace std;

int main()
{
    string s;
    cin >> s;
    int y = 0, m = 0, d = 0;
    //y += (int)(s[0] - '0') * 1000 + (int)(s[1] - '0') * 100 + (int)(s[2] - '0') * 10 + (int)(s[3] - '0');
    m += (int)(s[5] - '0') * 10 + (int)(s[6] - '0');
    d += (int)(s[8] - '0') * 10 + (int)(s[9] - '0');
    if (m > 4)
    {
        cout << "TBD" << endl;
        return 0;
    }
    else if (m < 4)
    {
        cout << "Heisei" << endl;
        return 0;
    }
    if (d > 30)
    {
        cout << "TBD" << endl;
        return 0;
    }
    else
    {
        cout << "Heisei" << endl;
    }
    return 0;
}