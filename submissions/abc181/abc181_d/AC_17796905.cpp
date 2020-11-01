#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
random_device rnd;
mt19937 mt(rnd());
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;

bool check(int n, map<int, int> mp)
{
    while (n != 0) {
        int t = n % 10;
        if (mp[t] == 0) {
            return false;
        }
        mp[t]--;
        n /= 10;
    }
    return true;
}
bool check1(string s, string t)
{
    sort(ALL(s));
    sort(ALL(t));

    return s == t;
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    map<int, int> mp;

    rep(i, n)
    {
        mp[s[i] - '0']++;
    }
    bool f = false;
    f |= check1(s, "8");
    f |= check1(s, "16");
    f |= check1(s, "32");
    f |= check1(s, "48");
    f |= check1(s, "56");
    f |= check1(s, "64");
    f |= check1(s, "72");
    f |= check1(s, "88");
    f |= check1(s, "96");
    if (f) {
        cout << "Yes" << endl;
        return 0;
    }

    int cur = 96 + 8;
    while (cur <= 1010) {

        if (check(cur, mp)) {
            cerr << cur << endl;
            cout << "Yes" << endl;
            return 0;
        }
        cur += 8;
    }
    cout << "No" << endl;
    return 0;
}