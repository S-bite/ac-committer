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
    string s;
    cin >> s;

    vector<int> num;
    vector<char> op;
    rep(i, s.size())
    {
        if (i % 2 == 0)
            num.push_back(s[i] - '0');
        else
            op.push_back(s[i]);
    }
    op.push_back('@');
    int ans = 0;
    int cur = 0;
    bool haszero = false;
    char prev = '@';
    while (true)
    {
        if (op[cur] == '+')
        {
            if (num[cur] != 0)
            {
                ans++;
            }
        }
        else
        {
            while (op[cur] == '*')
            {
                if (num[cur] == 0)
                {
                    haszero = true;
                }
                cur++;
            }
            if (num[cur] == 0)
            {
                haszero = true;
            }
            if (!haszero)
                ans++;
            haszero = false;
        }
        cur++;
        if (cur >= num.size())
            break;
    }

    cout << ans << endl;
    return 0;
}
