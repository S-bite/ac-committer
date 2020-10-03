#include <bits/stdc++.h>
#include "atcoder/all"
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using namespace atcoder;
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

void dfs(vector<int> &c, vector<bool> &canStart, vector<bool> &canEnd, int n, int pos, int val)
{
    // cerr << pos << endl;
    if (pos == 2 * n)
    {
        cout << "Yes" << endl;
        exit(0);
    }
    if (c[pos] == 0 && canStart[pos] == false)
        return;
    if (c[pos] != 0 && val != 0 && abs(c[pos]) != abs(val))
    {
        return;
    }
    val = c[pos];
    if (c[pos] == 0)
    {
        if (val != 0)
        {
            if (canEnd[pos + val] == false)
            {
                return;
            }
            canStart[pos + val] = canEnd[pos + val] = false;
            c[pos] = val;
            c[pos + val] = -val;
            dfs(c, canStart, canEnd, n, pos + 1, val);
            canStart[pos + val] = canEnd[pos + val] = true;
            c[pos] = 0;
            c[pos + val] = 0;
        }
        else
        {
            rep(i, 1, 2 * n - pos)
            {
                if (c[pos + val] > 0)
                {
                    break;
                }
                val = i;
                if (canEnd[pos + val] == false)
                {
                    continue;
                }

                canStart[pos + val] = canEnd[pos + val] = false;
                c[pos] = val;
                c[pos + val] = -val;
                dfs(c, canStart, canEnd, n, pos + 1, val);
                canStart[pos + val] = canEnd[pos + val] = true;
                c[pos] = 0;
                c[pos + val] = 0;
            }
        }
    }
    else
    {
        dfs(c, canStart, canEnd, n, pos + 1, val);
    }
    return;
}

// bool check(vector<int> ans, vector<bool> &canStart, VI canEnd, int n)
// {
//     int pos = 0;
//     int val = -1;
//     while (pos < 2 * n)
//     {
//         val = ans[pos];
//         if (val < 0)
//             return false;
//         rep(i, val)
//         {
//             if (pos >= 2 * n)
//                 return false;
//             if (ans[pos] != val)
//             {
//                 return false;
//             }
//             pos++;
//         }
//         rep(i, val)
//         {
//             if (pos >= 2 * n)
//                 return false;
//             if (ans[pos] != -val)
//             {
//                 return false;
//             }
//             pos++;
//         }
//     }
//     return true;
// }

int main()
{

    //cout << check(vector<int>({1, -1, 3, 3, 3, -3, -3, -3}), 4) << endl;

    int n;
    cin >> n;
    VI a(n), b(n);
    VI c(2 * n, 0);
    rep(i, n)
    {
        cin >> a[i] >> b[i];
        if (a[i] != -1)
            a[i]--;
        if (b[i] != -1)
            b[i]--;
    }
    vector<bool> canStart(2 * n, true);
    vector<bool> canEnd(2 * n, true);

    rep(i, n)
    {
        if (a[i] != -1 && b[i] != -1)
        {
            int x = b[i] - a[i];
            if (c[a[i]] != 0 || c[b[i]] != 0)
            {
                cout << "No" << endl;
                exit(0);
            }
            c[a[i]] = x;
            c[b[i]] = -x;

            canStart[a[i]] = canEnd[a[i]] = canStart[b[i]] = canEnd[b[i]] = false;
        }
        else if (a[i] != -1)
        {
            canEnd[a[i]] = false;
        }
        else if (b[i] != -1)
        {
            canStart[b[i]] = false;
        }
    }
    dfs(c, canStart, canEnd, n, 0, 0);
    cout << "No" << endl;

    return 0;
}