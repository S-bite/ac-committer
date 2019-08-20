#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#define MOD (ll)(1e9 + 7)
using namespace std;
map<int,vector<int>> g;
int dfs(int emp){
    int maxcost=-1;
    int mincost=(1<<30);
    if (g[emp].size()==0){
        return 1;
    }
    for (auto x : g[emp]){
        int cost=dfs(x);
        maxcost=max(maxcost,cost);
        mincost=min(mincost,cost);
    }
    return maxcost+mincost+1;
}

int main(){

    int n;
    cin>>n;
    rep(i,n-1){
        int b;
        cin>>b;
        g[b].push_back(i+2);
    }  
    cout<<dfs(1)<<endl;

    return 0;
}