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
#define MOD 1000000007ll
using namespace std;
bool has(vector<int> &v,int n){
    rep(i,v.size()){
        if (v[i]==n)
            return true;
    }
    return false;
}
int main(void)
{
    int n,m;
    cin>>n>>m;
    map<int,vector<int>> g;
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    deque<vector<int>> q;
    q.push_back({0});
    int ans=0;
    while(!q.empty()){
        vector<int> path=q.front();
        q.pop_front();
        if (path.size()==n){
            ans++;
            continue;
        }
        int now=path.back();
        for (auto next:g[now]){
            if (!has(path,next)){
                path.push_back(next);
                q.push_back(path);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
