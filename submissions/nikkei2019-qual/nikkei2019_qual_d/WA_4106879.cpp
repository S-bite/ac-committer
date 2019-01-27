#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MOD (1000000007ll)
#define ALL(x) x.begin(), x.end()

using namespace std;
struct node
{
    int id;
    int root;
    vector<int> to;
    vector<int> from;
};
int main()
{
    int n, m;
    cin >> n >> m;
    node t[n];
    rep(i, n)
    {
        t[i] = node{i, -1, {}, {}};
    }
    rep(i, n + m - 1)
    {
        int from, to;
        cin >> from >> to;
        from--;
        to--;
        t[from].to.push_back(to);
        t[to].from.push_back(from);
    }
    int rootid = 0;
    while (!t[rootid].from.empty())
    {
        rootid = t[rootid].from[0];
    }
    //cout << rootid << endl;
    int nowid = rootid;
    int nextid;
    t[rootid].root = -1;
    while (!t[nowid].to.empty())
    {
        for (auto ind : t[nowid].to)
        {
            if (t[ind].from.size() == 1)
            {
                t[ind].root = nowid;
                nextid = ind;
            }
            t[ind].from.erase(remove(ALL(t[ind].from), nowid), t[ind].from.end());
        }
        nowid = nextid;
    }
    rep(i, n)
    {
        cout << t[i].root + 1 << endl;
    }
    return 0;
}