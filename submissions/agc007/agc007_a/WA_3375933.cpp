#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  int bf=-1,bl=-1;
  rep(i,h){
    int f=-1,l=-1;
    string s;
    cin>>s;
    rep(j,w){
      cout<<w<<":"<<s[j]<<endl;
      if (s[j]=='#'){
        if(f==-1) f=j;
        else l=j;
      }
    }
//      cout<<f<<","<<l<<endl;
      if (bl!=-1 and bl!=f){
        cout<<"Impossible"<<endl;
        return 0;
      }
      bl=l;
  }
  cout<<"Possible"<<endl;
  return 0;
}
