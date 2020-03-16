#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;
int h, w, k;

bool check(int num)
{
    bool prevone = false;
    while (num != 0)
    {
        int cur = num % 2;
        if (cur == 1)
        {
            if (prevone == true)
                return false;
            prevone = true;
        }
        else
        {
            prevone = false;
        }
        num /= 2;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    cin >> h >> w >> k;
    vector<vector<ll>> dp(h + 1, vector<ll>(w, 0));
    dp[0][0] = 1;
    rep(i, 1, h + 1)
    {
        rep(pattern, 1 << (w - 1))
        {
            if (check(pattern) == false)
                continue;
            vector<int> order(w);
            rep(j, w) order[j] = j;
            rep(j, w - 1)
            {
                if (((pattern >> j) & 1) == 1)
                {
                    swap(order[j], order[j + 1]);
                }
            }
            rep(j, w)
            {
                dp[i][j] += dp[i - 1][order[j]];
                dp[i][j] %= MOD;
            }
        }
    }
    /*
    rep(i, h + 1)
    {
        for (auto x : dp[i])
            cerr << x << " ";
        cerr << endl;
    }*/
    cout << dp[h][k - 1] << endl;
    return 0;
}
