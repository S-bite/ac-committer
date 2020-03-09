#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const ll INF = 1ll << 60;

int main()
{
    string s;
    cin >> s;
    string t = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
    vector<string> notes = {"Do", "", "Re", "", "Mi", "Fa", "", "So", "", "La", "", "Si"};
    rep(i, t.size())
    {
        bool flag = true;
        rep(j, s.size())
        {
            if (s[j] != t[i + j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << notes[i] << endl;
            return 0;
        }
    }
    return 0;
}