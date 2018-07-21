#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  struct node{
    int s;
    int d;
    int N;
    bool operator<( const node& tmp ) const {
      return (d!=tmp.d)?d<tmp.d:(abs(N/2-s)<abs(N/2-tmp.s));
    };
  };
  cin>>N>>M;
  int a[M],b[M];
  node n[M];
  for(int i=0;i<M;i++){
    cin>>a[i]>>b[i];
    node t={min(a[i],b[i]),abs(a[i]-b[i]),N};
    n[i]=t;
  }
  sort(n,n+M);
  //for(int i=0;i<M;i++)cout<<n[i].d<<endl;
  bool check[M]={false};
  int ans=0;
  for(int i=0;i<M;i++){
    if (check[i]) continue;
    for(int j=i;j<M;j++){
      if (check[j]) continue;
      if(n[j].s<=n[i].s && n[j].s+n[j].d>n[i].s){
        check[j]=true;
      }
    }
//    cout<<n[i].s<<endl;
    ans++;
  }
  cout<<ans<<endl;
}
