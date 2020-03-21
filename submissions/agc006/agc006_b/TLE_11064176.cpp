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

void check(vector<int> &ans, int x)
{
    while (ans.size() != 1)
    {
        vector<int> nans(ans.size() - 2);
        rep(i, ans.size() - 2)
        {
            nans[i] = ans[i] + ans[i + 1] + ans[i + 2] -
                      max({ans[i], ans[i + 1], ans[i + 2]}) -
                      min({ans[i], ans[i + 1], ans[i + 2]});
        }
        ans = nans;
    }
    assert(ans[0] == x);
}

int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n >> x;
    n = 2 * n - 1;

    if (x == 1 || x == n)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        if (n == 3 && x == 2)
        {
            cout << "1 2 3" << endl;
            return 0;
        }

        vector<int> ans(n, -1);
        map<int, bool> used;
        used[x] = used[1] = used[n] = true;
        if (x <= n / 2)
        {
            ans[n / 2 - 2] = n;
            ans[n / 2 - 1] = 1;
            ans[n / 2] = x;
            ans[n / 2 + 1] = n - 1;
            used[n - 1] = true;
        }
        else
        {
            ans[n / 2 - 2] = 1;
            ans[n / 2 - 1] = n;
            ans[n / 2] = x;
            ans[n / 2 + 1] = 2;
            used[2] = true;
        }
        int cur = 1;
        rep(i, n)
        {
            if (ans[i] != -1)
                continue;
            while (used[cur])
                cur++;
            ans[i] = cur;
            used[cur] = true;
        }
        rep(i, n) cout << ans[i] << endl;
        check(ans, x);
    }
    return 0;
}
