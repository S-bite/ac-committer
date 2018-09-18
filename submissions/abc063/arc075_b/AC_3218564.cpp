#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;
bool enough(vector<ll>h,ll T,ll a,ll b){
  ll d=a-b;
  ll t=0;
  rep(i,h.size()){
    if (h[i]-b*T>0){
      t+=(h[i]-b*T+d-1)/d;
    }
  }
  return t<=T;
}
int main(){
  ll n,a,b;
  cin>>n>>a>>b;
  vector<ll>h;
  rep(i,n){
    ll t;
    cin>>t;
    h.push_back(t);
  }
  ll upper=(1<<30)/b+1,lower=0;
  while (upper!=lower+1){
  //  cout<<upper<<","<<lower<<endl;
    ll T=(upper+lower)/2;
    if(enough(h,T,a,b)){
      upper = T;
    }else lower=T;
  }
  cout<<upper<<endl;
}
