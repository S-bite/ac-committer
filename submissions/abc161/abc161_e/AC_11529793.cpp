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
vector<ll> ans;

int main()
{
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    int workMax = 0;
    int cur = 0;
    VI candid;
    rep(i, n)
    {
        if (cur != 0)
        {
            cur--;
        }
        else
        {
            if (s[i] == 'o')
            {
                workMax++;
                cur = c;
                candid.push_back(i);
            }
        }
    }
    if (k < workMax)
    {
        cout << endl;
        return 0;
    }
    cur = candid.size() - 1;
    candid.push_back(IINF);
    VI ans;
    bool change = false;
    for (int i = n - 1; i >= 0; i--)
    {
        //cerr << cur << " " << candid[cur] << " " << i << endl;
        if (candid[cur] == i)
        {
            // cerr << "i" << change << endl;
            ans.push_back(candid[cur]);
            cur--;
            continue;
        }
        if (cur == -1)
            break;
        if (s[i] == 'o' && candid[cur + 1] - i > c)
        {
            candid[cur] = i;
            cur--;
            if (cur == -1)
                break;
        }
    }

    sort(ALL(ans));

    rep(i, ans.size())
    {
        cout << ans[i] + 1 << endl;
    }

    return 0;
}
