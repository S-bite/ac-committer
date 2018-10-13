#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int gcd(int a,int b){
    if(a<b){
      int t=a;
      a=b;
      b=t;
    }
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(int a,int b){
  return ((ll)(a*b))/gcd(a,b);
}
int main(){
  //cout<<lcm(10000,100001)<<endl;
  int n,m;
  cin>>n>>m;
  string s,t;
  cin>>s>>t;
  ll ans=lcm(n,m);

  ll N=ans/n;
  ll M=ans/m;
  rep(i,n)rep(j,m){
    if (i*N<j*M) break;
    if (i*N==j*M){
  //    cout<<s[i*N]<<","<<t[j*M]<<endl;
      if (s[i]!=t[j]){
        cout<<-1<<endl;
        return 0;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
