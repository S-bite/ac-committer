#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  struct node{
    int s;
    int e;
    bool operator<( const node& tmp ) const {
      return e<tmp.e;
    };
  };
  cin>>N>>M;
  int a[M],b[M];
  node n[M];
  for(int i=0;i<M;i++){
    cin>>a[i]>>b[i];
    node t={a[i],b[i]};
    n[i]=t;
  }
  sort(n,n+M);
  //for(int i=0;i<M;i++)cout<<n[i].d<<endl;
  int ans=0,l=-1;
  for(int i=0;i<M;i++){
    if(n[i].s<=l and l<n[i].e) continue;
    ans++;
    l=n[i].e-1;
  }

  cout<<ans<<endl;
}
