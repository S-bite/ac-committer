#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n,0),b(n,0);
    priority_queue <pair<int,int>> p;
    vector <pair<int,int>> v;
    
    priority_queue<int>pq;
    deque<pair<int,int>> que;
    rep(i,n){
        cin>>a[i]>>b[i];
        if (a[i]<=m)
        v.push_back({m-a[i],-b[i]});
    }
    if (v.size()==0){
        cout<<0<<endl;
        return 0;
    }
    sort(ALL(v));
    ll ans=0;
    for (int i=0;i<m;i++){
        int add=max_element(ALL(v),[](pair<int,int> a, pair<int,int> b) {
                              return a.second > b.second;})->second;
      //  cerr<<add<<endl;
     if (add>=0){
         break;
     }
        ans-= add;
        rep (j,v.size()){
            if (-v[j].first==i){
               // cerr<<"*"<<i<<","<<v[j].first<<","<<v[j].second<<endl;
                v[j].second=1;
            }
            if (v[j].second==add){
                v[j].second=1;
                add=99;
            }
            
        }
    }
    cout<<ans<<endl;

    return 0;
}
