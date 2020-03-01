#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const int IINF = 1 << 29;
typedef vector<vector<int>> VVI;
typedef vector<int> VI;
typedef pair<int, int> PII;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    int tmp = k;
    string s;
    cin >> s;
    auto t = s;
    auto old = s;
    VI cost(n, 1);
    sort(ALL(t));
    rep(j, n)
    {
        cost[j] = (s[j] == old[j] ? 1 : 0);
        //  cerr << cost[j];
    }
    rep(i, n)
    {
        if (s[i] <= t[i])
            continue;
        for (int j = n - 1; j > i; j--)
        {
            // cerr << i << " " << j << endl;
            if (s[j] == t[i])
            {
                //   cerr << "ok" << endl;
                if (k >= cost[i] + cost[j])
                {
                    swap(s[i], s[j]);
                    k -= cost[i] + cost[j];
                    break;
                }
            }
        }
        cerr << s << endl;
        rep(j, n)
        {
            cost[j] = (s[j] == old[j] ? 1 : 0);
            //  cerr << cost[j];
        }
        //cerr << endl;
        //cerr << k << endl;
    }
    cout << s << endl;

    return 0;
}
