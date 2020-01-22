#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

int main(int argc, char const *argv[])
{
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int cur1 = 0, cur2 = 0;
    rep(i, n)
    {
        if (s[i] == 'c')
        {
            cout << "No" << endl;
        }
        else
        {
            if (s[i] == 'a' && cur1 < a + b)
            {
                cout << "Yes" << endl;
                cur1++;
            }
            else if (s[i] == 'b' && cur1 < a + b && cur2 < b)
            {
                cout << "Yes" << endl;
                cur1++;
                cur2++;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
