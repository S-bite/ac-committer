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

vector<string> ans;
map<string, bool> mp;
int n;

void dfs(string cur, int maxchar)
{

    if (cur.size() == n)
    {
        assert(mp[cur] == false);
        mp[cur] = true;
        ans.push_back(cur);
        return;
    }
    // cerr << cur << " " << maxchar << endl;
    rep(i, n)
    {
        if (i > maxchar + 1)
        {
            break;
        }
        if (i > maxchar)
        {
            dfs(cur + (char)('a' + i), i);
        }
        else
        {
            dfs(cur + (char)('a' + i), maxchar);
        }
    }
}

int main()
{
    cin >> n;
    dfs("", -1);
    sort(ALL(ans));
    for (auto s : ans)
    {
        cout << s << endl;
    }
    return 0;
}