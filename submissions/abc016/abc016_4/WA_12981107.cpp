//from https://atcoder.jp/contests/abc016/submissions/12979528?lang=ja
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll ax, ay, bx, by;
    int n;
    cin >> ax >> ay >> bx >> by;
    cin >> n;
    vll x(n+1), y(n+1);
    rep(i, n) cin >> x[i] >> y[i];
    x[n] = x[0];
    y[n] = y[0];
    auto f = [&](ll x, ll y) {
        return (ax - bx) * (by - y) - (bx - x) * (ay - by);
    };
    int cnt = 0;
    rep(i, n) if (f(x[i], y[i]) * f(x[i+1], y[i+1]) < 0) cnt++;
    cout << cnt/2 + 1 << endl;
}
