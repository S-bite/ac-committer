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
vector<string> d = {
    ".###..#..###.###.#.#.###.###.###.###.###.",
    ".#.#.##....#...#.#.#.#...#.....#.#.#.#.#.",
    ".#.#..#..###.###.###.###.###...#.###.###.",
    ".#.#..#..#.....#...#...#.#.#...#.#.#...#.",
    ".###.###.###.###...#.###.###...#.###.###."};
char match(vector<string> target)
{
    rep(i, 10)
    {
        int start = 1 + 4 * i;
        bool ok = true;
        rep(j, 5)
        {
            if (d[j].substr(start, 3) != target[j])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            return '0' + i;
        }
    }
    return '?';
}
int main()
{
    int n;
    cin >> n;
    vector<string> s(5);
    rep(i, 5)
    {
        cin >> s[i];
    }
    string ans = "";
    rep(i, n)
    {
        int start = 1 + 4 * i;
        vector<string> t(5, "");
        rep(j, 5)
        {
            t[j] = s[j].substr(start, 3);
        }
        ans += match(t);
    }
    cout << ans << endl;
    return 0;
}
