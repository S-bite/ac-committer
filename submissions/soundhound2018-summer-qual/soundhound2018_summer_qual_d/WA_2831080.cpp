#include<bits/stdc++.h>

using namespace std;
struct edge{
  int to,cost_y,cost_s;
};

int main(){
  long long int n,m,s,t;
  cin>>n>>m>>s>>t;
  vector<edge> edges[n];

  //cout<<&edges[0]<<","<<&edges[1]<<endl;
  int u[m],v[m],a[m],b[m];

  for(int i=0;i<m;i++){
    cin>>u[i]>>v[i]>>a[i]>>b[i];
    edge e1={u[i]-1,a[i],b[i]};
    edges[v[i]-1].push_back(e1);
    edge e2={v[i]-1,a[i],b[i]};
    edges[u[i]-1].push_back(e2);

}
  for(int i=0;i<n;i++){
    for(edge e:edges[i]){
      //cout<<i<<","<<e.to<<","<<e.cost_s<<","<<e.cost_y<<endl;
    }
  }
  int min_y[n]={};
  int min_s[n]={};
  for(int i=0;i<n;i++){

  }

}
