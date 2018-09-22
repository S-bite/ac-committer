#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;


int main(){
  int a,b,c,s;
  cin>>a>>b>>c>>s;
  if(a+b+c<=s and s<=a+b+c+3) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
