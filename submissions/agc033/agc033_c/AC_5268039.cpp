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
    int snode = -1;
    rep(i, leaf.size())
    {
        if (diam < dist[leaf[i]])
        {
            diam = dist[leaf[i]];
            snode = leaf[i];
        }
    }

    vector<int> leaf2;
    map<int, int> dist2;
    map<int, bool> visited2;
    queue<int> que2;
    que2.push(snode);
    visited2[snode] = true;
    dist2[snode] = 0;
    while (!que2.empty())
    {
        int node = que2.front();
        visited2[node] = true;
        que2.pop();
        if (mp[node].size() == 1)
            leaf2.push_back(node);
        rep(i, mp[node].size())
        {
            int next = mp[node][i];
            if (visited2[next] == false)
            {
                dist2[next] = dist2[node] + 1;
                que2.push(next);
            }
        }
    }

    diam = 0;
    rep(i, leaf2.size())
    {
        diam = max(diam, dist2[leaf2[i]]);
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
