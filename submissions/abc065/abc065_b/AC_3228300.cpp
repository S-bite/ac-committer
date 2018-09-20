#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n];
  rep(i,n){
    cin>>a[i];
    a[i]--;
  }
  int now=0;
  rep(i,n){
    now=a[now];
    if (now==1) {cout<<(i+1)<<endl; return 0;}

  }
  cout<<-1<<endl;
  return 0;
}
