#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

//座標pに集まることにした時の体力消費を計算する関数
ll calc(vector<ll> &x, int p)
{
    ll ret = 0;
    for (auto y : x)
    {
        ret += (y - p) * (y - p);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];
    //大きい数で初期化しておく
    ll ans = INF;
    //1<=x<=100なので、1～100までの座標をすべて試す
    rep(i, 100)
    {
        //答えを小さいほうに更新
        ans = min(ans, calc(x, i));
    }
    cout << ans << endl;
    return 0;
}
