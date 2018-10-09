#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
int n;
cin>>n;
string s,t;
cin>>s>>t;
int ans=2*n;
rep(i,n){
  if (s.substr(n-i-1,i+1)==t.substr(0,i+1)){
    ans=2*n-i-1;
  }
}
cout<<ans<<endl;
return 0;
}
