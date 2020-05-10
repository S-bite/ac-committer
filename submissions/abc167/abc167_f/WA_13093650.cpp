#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
random_device rnd;
mt19937 mt(rnd());

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 998244353;

PII get()
{
    int ret = 0;
    string s;
    cin >> s;
    bool posi = true, nega = true;
    rep(i, s.size())
    {
        if (s[i] == '(')
            ret++;
        else
            ret--;
        posi &= ret >= 0;
        nega &= ret <= 0;
    }
    int type = 0;
    if (ret < 0 && nega)
        type = 1;
    else if (ret > 0 && posi)
        type = -1;
    return {type, ret};
}

int main()
{
    int n;
    cin >> n;
    vector<PII> v(n);
    rep(i, n)
    {
        v[i] = get();
    }
    ll cur = 0;
    sort(ALL(v));
    if (v[0].first != -1 || v[n - 1].first != 1)
    {
        cout << "No" << endl;
        return 0;
    }
    rep(i, n)
    {
        cur += v[i].second;
        if (cur < 0)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    if (cur == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}