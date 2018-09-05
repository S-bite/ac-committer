#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for (ll i=0;i<(ll)(n);i++)
#define INF (1ll<<60)
using namespace std;
ll f(vector<ll> a,vector<ll>s,int t){
  ll e=a.size();
  ll n=e/3;

  sort(&a[0],&a[t]);
  sort(&a[t],&a[e],greater<ll>());
  //rep(i,7)cout<<s[i]<<endl;

  ll ret=s[t];
  //cout<<ret<<endl;
  rep(i,t-n)ret-=a[i];
  //cout<<ret<<endl;
  ret-=s[3*n]-s[t];
  //cout<<ret<<endl;

  rep(i,2*n-t)ret+=a[t+i];
  //cout<<ret<<endl;

  return ret;
}
int main(){
  ll n;
  cin>>n;
  vector<ll> a;
  vector<ll>s;
  s.push_back(0);
  rep(i,3*n){ll t; cin>>t; a.push_back(t);s.push_back(s.back()+t);}
  ll  ans=-INF;//f(a,s,3);
  for (ll i=    n;i<=2*n;i++) ans=max(ans,f(a,s,i));
    cout<<ans<<endl;;
  return 0;
}
