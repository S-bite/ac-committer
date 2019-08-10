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
    map<int,int> mp;
    priority_queue <pair<int,int>> p;
    
    priority_queue<int>pq;
    rep(i,n){
        cin>>a[i]>>b[i];
        if (a[i]<=m){
        p.push({-a[i],b[i]});
        }
    }

    ll ans=0;
    for (int i=1;i<=m;i++){
          while ((-p.top().first<=i)&& (!p.empty())){
            pq.push(p.top().second);
            p.pop();
        }
        if (!pq.empty()){
        ans+=pq.top();
        pq.pop();}
    }
    cout<<ans<<endl;

    return 0;
}
