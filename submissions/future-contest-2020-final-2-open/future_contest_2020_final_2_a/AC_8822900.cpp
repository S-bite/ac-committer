#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;
int N, S, K;
vector<int> x(1000), y(1000), c(1000);
vector<map<int, vector<int>>> p(1000);

bool canConnect(int a, int b)
{
    return a != b && ceil(sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]))) <= c[a] + c[b];
}

vector<int> search(map<int, vector<int>> &g, map<int, vector<int>> &t, int tsize)
{
    int root;
    do
    {
        root = rand() % N;
    } while (g[root].size() == 0);

    map<int, bool> used;
    vector<int> ans;
    deque<int> que;
    ans.push_back(root);
    que.push_back(root);
    used[root] = true;
    while (ans.size() < tsize && !que.empty())
    {
        //cerr << (int)que.size() << endl;

        int cur = que.front();
        que.pop_front();
        for (auto x : g[cur])
        {
            if (used[x] == false)
            {
                ans.push_back(x);
                used[x] = true;
                que.push_back(x);
            }
            if (ans.size() == tsize)
                break;
        }
    }
    rep(i, tsize - ans.size())
    {
        ans.push_back(0);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cin >> N >> S;
    rep(i, N)
    {
        cin >> x[i] >> y[i] >> c[i];
    }
    vector<int> K(S);
    rep(i, S)
    {
        cin >> K[i];
        rep(j, 1, K[i])
        {
            int t;
            cin >> t;
            p[i][j - 1].push_back(t - 1);
            p[i][t - 1].push_back(j - 1);
        }
    }
    map<int, bool> used;
    map<int, vector<int>> g;
    int M = 0;
    vector<pair<int, int>> v;
    int treesize = 1;
    used[0] = true;
    rep(i, N)
    {
        if (used[i] == false)
            continue;
        rep(j, i + 1, N)
        {
            if (used[j] == true)
                continue;
            if (canConnect(i, j))
            {

                g[i].push_back(j);
                g[j].push_back(i);
                used[j] = true;
                M++;
                v.push_back({i, j});
                treesize++;
            }
        }
    }
    cout << M << endl;
    rep(i, M)
    {
        cout << v[i].first + 1 << " " << v[i].second + 1 << endl;
    }
    //return 0;
    cerr << treesize << endl;

    rep(i, S)
    {
        vector<int> ans = search(g, p[i], K[i]);
        for (auto x : ans)
        {
            cout << x + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
