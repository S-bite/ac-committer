#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(long long i=0;i<(ll)(n);i++)
using namespace std;
ll gcd(ll a,ll b){
    if(a<b){
      ll t=a;
      a=b;
      b=t;
    }
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
  return ((ll)(a*b))/gcd(a,b);
}
int main(){
  //cout<<lcm(10000,100001)<<endl;
  ll n,m;
  cin>>n>>m;
  string s,t;
  cin>>s>>t;
  ll ans=lcm(n,m);

  ll N=ans/n;
  ll M=ans/m;
  rep(i,n){
    if ((i*N)%M!=0) continue;
    ll j=(i*N)/M;
      //cout<<s[i]<<","<<t[j]<<endl;
      if (s[i]!=t[j]){
        cout<<-1<<endl;
        return 0;
      }
  }
  cout<<ans<<endl;
  return 0;
}
