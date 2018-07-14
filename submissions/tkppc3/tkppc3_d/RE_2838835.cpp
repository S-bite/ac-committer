#include<bits/stdc++.h>
using namespace std;
int main(){
int H,W,Q;
cin>>H>>W>>Q;
int sh[H+1],sw[W+1];
sh[0]=0;sw[0]=0;
for(int i=1;i<H+1;i++){
  int t;
  cin>>t;
  sh[i]=sh[i-1]+(i%2==1?1:-1)*t;
  }
for(int i=1;i<W+1;i++){
  int t;
  cin>>t;
  sw[i]=sw[i-1]+(i%2==1?1:-1)*t;
  }
for(int i=0;i<Q;i++){
  int sx,sy,ex,ey;
  cin>>sx>>sy>>ex>>ey;
  cout<<sw[ex]*sh[ey]-sw[sx]*sh[ey-1]-sw[ex-1]*sh[sy]<<endl;
}


}
