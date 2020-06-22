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
    vector<vector<int>> ps(n);
    VI cur(n, 0);
    map<int, int> line;
    rep(i, n)
    {
        int k;
        cin >> k;
        rep(j, k)
        {
            int t;
            cin >> t;
            line[t] = i;
            ps[i].push_back(t);
        }
    }
    // rep(i, n)
    // {
    //     for (auto &&x : ps[i])
    //     {
    //         cerr << x << " ";
    //     }
    //     cerr << endl;
    // }
    map<int, bool> mp1, mp2;
    priority_queue<int> p1;
    priority_queue<int> p2;
    rep(i, n)
    {
        p1.push(ps[i][0]);
        cur[i]++;
    }
    rep(i, n)
    {
        if (cur[i] == ps[i].size())
            continue;
        p2.push(ps[i][1]);
        cur[i]++;
    }
    int m;
    cin >> m;
    rep(i, m)
    {
        int ty;
        cin >> ty;
        // cerr << "q " << ty << endl;
        //       cerr << "del ";

        while (mp1[p1.top()])
        {
            //  cerr << p1.top() << " ";
            p1.pop();
        }
        //  cerr << endl;
        // cerr << "del ";
        while (!p2.empty() && mp2[p2.top()])
        {
            //   cerr << p2.top() << " ";

            p2.pop();
        }
        //   cerr << endl;
        if (ty == 1)
        {
            int ans = p1.top();

            int l = line[ans];
            cout << ans << endl;
            mp1[ans] = true;
            mp2[ans] = true;
            p1.push(ps[l][cur[l] - 1]);
            // cerr << "< " << ps[l][cur[l] - 1] << endl;
            mp2[ps[l][cur[l] - 1]] = true;

            if (cur[l] < ps[l].size())
            {
                //cerr << "+ " << ps[l][cur[l]] << endl;
                p2.push(ps[l][cur[l]]);
                cur[l]++;
            }
        }
        else
        {
            if (p2.empty() || p1.top() > p2.top())
            {
                int ans = p1.top();

                int l = line[ans];
                cout << ans << endl;
                mp1[ans] = true;
                mp2[ans] = true;

                p1.push(ps[l][cur[l] - 1]);
                mp2[ps[l][cur[l] - 1]] = true;
                //cerr << "< " << ps[l][cur[l] - 1] << endl;

                if (cur[l] < ps[l].size())
                {
                    // cerr << "+ " << ps[l][cur[l]] << endl;
                    p2.push(ps[l][cur[l]]);
                    cur[l]++;
                }
            }
            else
            {
                int ans = p2.top();
                int l = line[ans];
                cout << ans << endl;
                mp1[ans] = true;
                mp2[ans] = true;

                if (cur[l] < ps[l].size())
                {
                    // cerr << "+ " << ps[l][cur[l]] << endl;
                    p2.push(ps[l][cur[l]]);
                    cur[l]++;
                }
            }
        }
    }

    return 0;
}
