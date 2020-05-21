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
const int IINF=1<<30;
const ll INF=1ll<<60;
const ll MOD = 1000000007;
int n;
vector<lld> dijkstra(map<int,vector<pair<int,lld>>> &g,int start){
    priority_queue<pair<lld,int>,vector<pair<lld,int> >,greater<pair<lld,int>>> pque;
    pque.push({0,start});
    vector<lld> ret(n+2,INF);
    while (!pque.empty()){
        auto cost=pque.top().first;
        auto cur=pque.top().second;
        pque.pop();
        if (ret[cur]<=cost) continue;
        ret[cur]=cost;
         for (auto x:g[cur]){
             int next=x.first;
             lld d=x.second;
             pque.push({cost+d,next});
         }
     }

    return ret;
} 

lld dist(vector<lld> &a,vector<lld> &b){
    return max((lld)0,sqrtl((a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]))-a[2]-b[2]);
}

int main(){
    lld x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    cin>>n;
    vector<vector<lld>> p(n+2,vector<lld>(3));
    p[0]={x1,y1,0};
    p[1]={x2,y2,0};
    rep(i,n){
        cin>>p[2+i][0]>>p[2+i][1]>>p[2+i][2];
    }
    map<int,vector<pair<int,lld>>> g;
    rep(i,n+2){
        rep(j,n+2){
            if (i==j) continue;
           // cerr<<i<<" -> "<<j<<":"<<dist(p[i],p[j])<<endl;
            g[i].push_back({j,dist(p[i],p[j])});
        }
    }
    auto cost=dijkstra(g,0);
    cout<<fixed<<setprecision(18)<<cost[1]<<endl;
    return 0;
}