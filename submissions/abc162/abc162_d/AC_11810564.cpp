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

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    VI sumr(n + 1, 0), sumg(n + 1, 0), sumb(n + 1, 0);
    rep(i, n)
    {
        sumr[i + 1] = sumr[i];
        sumg[i + 1] = sumg[i];
        sumb[i + 1] = sumb[i];
        if (s[i] == 'R')
            sumr[i + 1]++;
        if (s[i] == 'G')
            sumg[i + 1]++;
        if (s[i] == 'B')
            sumb[i + 1]++;
    }
    ll ans = 0;
    map<char, bool> mp;
    rep(i, n)
    {
        rep(j, i + 1, n)
        {

            if (s[i] == s[j])
                continue;
            int dist = j - i;
            mp.clear();
            mp[s[i]] = true;
            mp[s[j]] = true;
            if (mp['R'] == false)
            {
                ans += sumr[n] - sumr[j];
                if (j + dist < n && s[j + dist] == 'R')
                    ans--;
            }
            if (mp['G'] == false)
            {
                ans += sumg[n] - sumg[j];
                if (j + dist < n && s[j + dist] == 'G')
                    ans--;
            }
            if (mp['B'] == false)
            {
                ans += sumb[n] - sumb[j];
                if (j + dist < n && s[j + dist] == 'B')
                    ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}