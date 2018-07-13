#include<bits/stdc++.h>
#define INF 2000000001
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

vector<int> s_cost_s;
vector<int> s_cost_y;
vector<int> t_cost_s;
vector<int> t_cost_y;
vector<bool> q;
for(int i=0;i<n;i++){
  q.push_back(true);
  s_cost_y.push_back((i==s-1)?0:INF);
  t_cost_s.push_back((i==t-1)?0:INF);

}

while (find(q.begin(), q.end(), true)!=q.end()){
  int index=0;
  int m=INF;
  for(int i=0;i<n;i++){
    if(q[i] and s_cost_y[i]<m){index=i;m=s_cost_y[i];}
  }
  q[index]=false;
  for(edge e:edges[index]){
    s_cost_y[e.to]=min(s_cost_y[e.to],s_cost_y[index]+e.cost_y);
    }
  }

  for(int i=0;i<n;i++){
    q[i]=true;
  }
  while (find(q.begin(), q.end(), true)!=q.end()){
    int index=0;
    int m=INF;
    for(int i=0;i<n;i++){
      if(q[i] and t_cost_s[i]<m){index=i;m=t_cost_s[i];}
    }
    q[index]=false;
    for(edge e:edges[index]){
      t_cost_s[e.to]=min(t_cost_s[e.to],t_cost_s[index]+e.cost_s);
      }
    }

      for(int i=0;i<n;i++){
        long long int a=1000000000000000;
        int m=INF;
        for(int j=i;j<n;j++){

          m=min(m,s_cost_y[j]+t_cost_s[j]);
        }
        cout<<a-m<<endl;
      }
}
