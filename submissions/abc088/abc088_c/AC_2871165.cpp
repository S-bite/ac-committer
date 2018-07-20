#include<bits/stdc++.h>
using namespace std;
int main(){
  int c[3][3];
  for(int i=0;i<3;i++)for(int j=0;j<3;j++)cin>>c[i][j];
  bool f=true;
  for(int i=0;i<2;i++){
  if(c[0][i]-c[0][i+1]!=c[1][i]-c[1][i+1] or c[1][i]-c[1][i+1]!=c[2][i]-c[2][i+1]) f=false;
  if(c[i][0]-c[i+1][0]!=c[i][1]-c[i+1][1] or c[i][1]-c[i+1][1]!=c[i][2]-c[i+1][2]) f=false;
}
  cout<<(f?"Yes":"No")<<endl;
}
