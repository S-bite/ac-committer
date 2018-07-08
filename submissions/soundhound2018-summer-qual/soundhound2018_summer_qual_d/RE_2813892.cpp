#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,s,t;
  cin>>n>>m>>s>>t;
  long long int u[n],v[n],a[n],b[n];
  long long int gy[n][n],gs[n][n];
  for(int x=0;x<n;x++)for(int y=0;y<n;y++){
    gy[x][y]=10000000000+1;
    gs[x][y]=10000000000+1;
  }

  for(int i=0;i<m;i++){
    cin>>u[i]>>v[i]>>a[i]>>b[i];
    gy[u[i]-1][v[i]-1]=a[i];
    gy[v[i]-1][u[i]-1]=gy[u[i]-1][v[i]-1];
    gs[u[i]-1][v[i]-1]=b[i];
    gs[v[i]-1][u[i]-1]=gs[u[i]-1][v[i]-1];
  }

  bool f=true;
  while (f){
    f=false;
    for(int x=0;x<n;x++)for(int y=0;y<n;y++){
      if(x==y){
        gy[x][y]=0;
        gy[y][x]=0;
        gs[x][y]=0;
        gs[y][x]=0;
        continue;
      }
      for(int i=0;i<n;i++){
        if(i==x or i==y) continue;
//        cout<<x<<","<<y<<","<<i<<endl;
        if (gy[x][y]==gy[x][i]+gy[i][y] or gs[x][y]==gs[x][i]+gs[i][y]) continue;
        gy[x][y]=min(gy[x][y],gy[x][i]+gy[i][y]);
        gy[y][x]=gy[x][y];
        gs[x][y]=min(gs[x][y],gs[x][i]+gs[i][y]);
        gs[y][x]=gs[x][y];
        if(gy[x][y]==gy[x][i]+gy[i][y] or gs[x][y]==gs[x][i]+gs[i][y])f=true;

      }
    }
  }
  for(int i=0;i<n;i++){
    long long int low=100000000001;
    for(int j=0;j<n;j++){
      if (j<i)continue;
      low=min(low,gy[s-1][j]+gs[j][t-1]);
    //  cout<<low<<","<<j<<endl;
    }
    cout<<1000000000000000-low<<endl;
  }
}
