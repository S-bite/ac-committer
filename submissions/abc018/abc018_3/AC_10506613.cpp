#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using P = pair<int, int>;

const int IINF = 1 << 29;
const ll INF = 1ll << 60;

bool is_valid(int y, int x, int r, int c)
{
    return 0 <= y && y < r && 0 <= x && x < c;
}

void update(VVI &g, int y, int x, int k, int r, int c)
{
    k--;

    //    cerr << y << " " << x << endl;
    int ny = y + k;
    int width = 0;
    while (ny >= y - k)
    {
        rep(nx, x - width, x + width + 1)
        {
            if (is_valid(ny, nx, r, c))
            {
                g[ny][nx] = 0;
            }
        }
        ny--;
        width = k - abs(y - ny);
    }
}

bool is_ok(vector<P> &p, int y, int x, int k)
{
    rep(i, p.size())
    {
        if (abs(p[i].first - y) + abs(p[i].second - x) < k)
        {
            // cerr << a.first << " " << a.second << endl;
            //swap(p[0], p[i]);
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int r, c, k;
    cin >> r >> c >> k;
    VVI g(r, VI(c, -1));
    vector<P> p;
    rep(i, r)
    {
        string s;
        cin >> s;
        rep(j, c)
        {
            if (s[j] == 'o')
            {
                g[i][j] = 0;
            }
            else
            {
                g[i][j] = 1;
                p.push_back({i, j});
                //  cerr << "+" << i << " " << j << endl;
            }
        }
    }

    int ans = 0;
    if (false)
    {
        rep(i, k - 1, r - k + 1)
        {
            rep(j, k - 1, c - k + 1)
            {
                //cerr << i << " " << j << endl;
                if (g[i][j] == 1)
                    continue;
                if (is_ok(p, i, j, k))
                {
                    cout << 1;
                    ans++;
                }
                else
                {
                    cout << 0;
                }
            }
            cout << endl;
        }
    }
    else
    {
        VVI h(r, VI(c, 1));
        for (auto x : p)
        {
            update(h, x.first, x.second, k, r, c);
        }
        rep(i, k - 1, r - k + 1)
        {

            rep(j, k - 1, c - k + 1)
            {
                ans += h[i][j];
            }
        }
    }

    cout << ans << endl;
    return 0;
}
