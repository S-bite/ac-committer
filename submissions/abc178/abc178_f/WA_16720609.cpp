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
    VI a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    VI order(n), inv(n);

    rep(i, n)
    {
        order[i] = n - 1 - i;
    }
    shuffle(ALL(order), mt);
    rep(i, n)
    {
        inv[order[i]] = i;
    }

    auto starttime = clock();
    while ((double(clock() - starttime) / CLOCKS_PER_SEC < 1.8))
    {
        bool ok = true;
        rep(i, n)
        {
            if (a[i] == b[order[i]])
            {
                ok = false;
                bool ng = true;
                rep(j, 40)
                {
                    int r = mt() % n;
                    if (a[order[r]] != b[order[i]] && a[order[i]] != b[order[r]])
                    {
                        ng = false;
                        swap(order[i], order[r]);
                        break;
                    }
                }
                if (ng)
                {
                    cerr << "2^-" << 40 << endl;
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
        if (ok)
        {
            cout << "Yes" << endl;
            rep(i, n)
            {
                cout << b[order[i]] << " ";
            }
            cout << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}