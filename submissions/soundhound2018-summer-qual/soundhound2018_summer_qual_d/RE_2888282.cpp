#include<bits/stdc++.h>
#define INF 20000000001
using namespace std;
struct edge{
  int to,cost_y,cost_s;
};

int main(){
  long long int n,m,s,t;
  cin>>n>>m>>s>>t;
  unsigned long int d_s[n][n]={INF};
  cout<<"t"<<endl;
  vector<edge> edges[n];
  for(int i=0;i<n;i++){
    edge e={i,0,0};
    edges[i].push_back(e);
  }


  int u[m],v[m],a[m],b[m];

  for(int i=0;i<m;i++){
    cin>>u[i]>>v[i]>>a[i]>>b[i];
    edge e1={u[i]-1,a[i],b[i]};
    edges[v[i]-1].push_back(e1);
    edge e2={v[i]-1,a[i],b[i]};
    edges[u[i]-1].push_back(e2);
}

}
