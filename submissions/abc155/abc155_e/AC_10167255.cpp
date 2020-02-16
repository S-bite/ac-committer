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
    int n = s.size();
    vector<int> v(s.size());
    rep(i, s.size()) v[i] = s[i] - '0';

    vector<vector<int>> dp(s.size() + 1, vector<int>(2, 0));
    //0:10を下ろしてくることができない
    //0:10を下ろしてくることができる
    dp[0][0] = 0;
    dp[0][1] = 1;
    rep(i, n)
    {
        dp[i + 1][0] = min(
            //それはそうな遷移
            dp[i][0] + v[i],
            dp[i][1] + 10 - v[i]);
        dp[i + 1][1] = min(
            //これはわかるやつ。桁上がりしてないから、この桁で桁上がりさせるしかなくて、そのためにはv[i]に1を足せばいい
            dp[i][0] + v[i] + 1,
            //ここがわからん
            dp[i][1] + 10 - (v[i] + 1));
    }
    cout << dp[n][0] << endl;
    return 0;
}