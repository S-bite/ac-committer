#include <bits/stdc++.h>
using namespace std;
int main(){
  int D,N;
  cin>>D>>N;
  if (N==100) return -1;
  if (D==0) cout<<N<<endl;
  if (D==1) cout<<100*N<<endl;
  if (D==2) cout<<10000*N<<endl;
}
