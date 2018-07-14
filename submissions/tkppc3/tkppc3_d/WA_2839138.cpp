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
//for(int i=0;i<H+1;i++)cout<<"sh"<<i<<":"<<sh[i]<<endl;
//for(int i=0;i<W+1;i++)cout<<"sw"<<i<<":"<<sw[i]<<endl;

for(int i=0;i<Q;i++){
  int si,sj,ei,ej;
  cin>>si>>sj>>ei>>ej;
  //cout<<sx<<","<<sy<<","<<ex<<","<<ey<<endl;

  cout<<sh[ei]*sw[ej]-sh[si-1]*sw[ej]-sh[ei]*sw[sj-1]+sh[si-1]*sw[sj-1]<<endl;
}


}
