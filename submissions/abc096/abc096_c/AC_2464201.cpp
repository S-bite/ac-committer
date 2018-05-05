#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  int m[h][w]={};
  for (int i=0;i<h;i++){
    for (int j=0;j<w;j++){
      char c;
      cin>>c;
      if (c=='#') m[i][j]=1;
      }
  }
  string ans="Yes";
  for (int y=0;y<h;y++){
    for (int x=0;x<w;x++){
      if (m[y][x]==1){
        bool chkflg=true;
        if ((y>0)&&(m[y-1][x]==1)) chkflg=false;
        if ((y<h-1)&&(m[y+1][x]==1)) chkflg=false;
        if ((x>0)&&(m[y][x-1]==1)) chkflg=false;
        if ((x<w-1)&&(m[y][x+1]==1)) chkflg=false;
        if (chkflg) ans="No";
      }
    }
  }
  cout<<ans<<endl;
}
