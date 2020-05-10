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
vector<string> line;
pair<PII, int> get()
{
    int frontnum = 0;
    int backnum = 0;
    string s;
    cin >> s;
    line.push_back(s);
    int cur = 0;
    rep(i, s.size())
    {
        if (s[i] == '(')
            cur++;
        else
            cur--;
        chmax(frontnum, -cur);
    }
    cur = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '(')
            cur++;
        else
            cur--;
        chmax(backnum, cur);
    }
    return {{frontnum, backnum}, 0};
}

int main()
{
    int n;
    cin >> n;
    vector<pair<PII, int>> v(n);
    vector<pair<PII, int>> a, b;

    rep(i, n)
    {
        v[i] = get();
        v[i].second = i;
        if (v[i].first.first <= v[i].first.second)
        {
            a.push_back(v[i]);
        }
        else
        {
            b.push_back(v[i]);
        }
    }
    ll cur = 0;
    sort(ALL(a));
    sort(ALL(b));
    reverse(ALL(b));
    rep(i, a.size())
    {
        v[i] = a[i];
    }
    rep(i, b.size())
    {
        v[i + a.size()] = b[i];
    }
    rep(i, n)
    {
        for (auto &&c : line[v[i].second])
        {
            if (c == '(')
                cur++;
            else
                cur--;
            if (cur < 0)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    if (cur == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
