#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;
int main(){
  int n,m,x;
  cin>>n>>m>>x;
  int l=0,r=0;
  rep(i,m){
    int t;
    cin>>t;
    if(t<x) r++;else l++;
  }
  cout<<min(l,r)<<endl;
  return 0;
}
