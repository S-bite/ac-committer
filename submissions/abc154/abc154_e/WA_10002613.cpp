#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;
int c2i(char c)
{
    return c - '0';
}
int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int len = s.size();
    ll ans = 0;
    if (k == 1)
    {
        rep(i, len)
        {
            if (i == 0)
            {
                ans += c2i(s[i]);
            }
            else
            {
                ans += 9;
            }
        }
    }
    if (k == 2)
    {
        rep(i, len)
        {
            bool flag = false;
            rep(j, i + 1, len)
            {
                if (i == 0)
                {
                    if (flag)
                        ans += 1 * 9;
                    else
                        ans += 1 * c2i(s[j]);
                    ans += c2i(s[i] - 1) * 9;
                }
                else
                {
                    ans += 81;
                }
                flag |= s[j] != '0';
            }
        }
    }
    if (k == 3)
    {
        rep(i, len)
        {
            bool flag1 = false;
            rep(j, i + 1, len)
            {
                bool flag2 = false;

                rep(k, j + 1, len)
                {
                    if (i == 0)
                    {
                        if (flag1)
                        {
                            ans += 1 * 81;
                        }
                        else if (!flag1 && flag2)
                        {
                            ans += 1 * (c2i(s[j]) - 1) * 9;
                            ans += 1 * 1 * 9;
                        }
                        else
                        {
                            ans += 1 * 1 * c2i(s[k]);
                            ans += 1 * c2i(s[j] - 1) * 9;
                        }

                        ans += c2i(s[i] - 1) * 81;
                    }
                    else
                    {
                        ans += 9 * 9 * 9;
                    }
                    flag2 |= s[k] != '0';
                }
                flag1 |= s[j] != '0';
            }
        }
    }
    cout << max(0ll, ans) << endl;
    return 0;
}
