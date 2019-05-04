#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
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

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    vector<int> leaf;
    map<int, int> dist;
    map<int, bool> visited;
    queue<int> que;
    rep(i, 1, n + 1)
    {
        if (mp[i].size() == 1)
        {
            que.push(i);
            visited[i] = true;
            dist[i] = 0;
            break;
        }
    }
    while (!que.empty())
    {
        int node = que.front();
        visited[node] = true;
        que.pop();
        if (mp[node].size() == 1)
            leaf.push_back(node);
        rep(i, mp[node].size())
        {
            int next = mp[node][i];
            if (visited[next] == false)
            {
                dist[next] = dist[node] + 1;
                que.push(next);
            }
        }
    }
    int diam = 0;
    rep(i, leaf.size())
    {
        diam = max(diam, dist[leaf[i]]);
    }
    cerr << diam << endl;
    diam++;
    if (diam == 2)
    {
        cout << "Second" << endl;
    }
    else if (diam == 3)
    {
        cout << "First" << endl;
    }
    else if (diam % 3 != 2)
    {
        cout << "First" << endl;
    }
    else
    {
        cout << "Second" << endl;
    }
    return 0;
}
