#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const int IINF = 1 << 29;
typedef vector<vector<int>> VVI;
typedef vector<int> VI;
typedef pair<int, int> PII;

//2-swap
string trans1(string s, int n)
{

    string ret = s.c_str();
    rep(i, n)
    {
        rep(j, n)
        {
            string cur = s.c_str();
            swap(cur[i], cur[j]);
            if (cur < ret)
                ret = cur;
        }
    }
    return ret;
}

//3-swap
string trans2(string s, int n)
{
    string ret = s.c_str();
    rep(i, n)
    {
        rep(j, n)
        {
            rep(k, n)
            {
                if (i == j || j == k || k == i)
                    continue;
                string cur = s.c_str();
                char tmp = cur[i];
                cur[i] = s[j];
                cur[j] = s[k];
                cur[k] = tmp;

                if (cur < ret)
                    ret = cur;
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{

    int n, k;
    cin >> n >> k;
    if (k % 2 == 1)
        k++;
    string s;
    cin >> s;
    vector<string> dp(k + 1, s);

    rep(i, k + 1)
    {
        if (i + 2 <= k)
        {

            dp[i + 2] = min(dp[i + 2], trans1(dp[i], n));
        }
        if (i + 3 <= k)
        {
            dp[i + 3] = min(dp[i + 3], trans2(dp[i], n));
        }
    }
    cout << dp[k] << endl;
    return 0;
}
