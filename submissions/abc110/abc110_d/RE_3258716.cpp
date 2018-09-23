#include<bits/stdc++.h>
#define ll unsigned long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define MOD 1000000007ll
using namespace std;
ll c(int n,int k){

}

vector<ll> factoring(ll n){
  ll i=2;
  vector<ll> ret;
  while (n!=1){
    if(n%i==0){
      int e=0;
      while(n%i==0){n/=i;e++;}
      //cout<<i<<","<<e<<endl;
      ret.push_back(e);//make_pair(i,e));
    }
    i++;
  }
  return ret;
}

ll factorial(ll n){
  if (n==1) return 1;
  else return ((n*factorial(n-1))%MOD);
}

int main(){
  //cout<<factorial(100000)<<endl;
  ll n,m,ans=1;
  //cout<<ans<<endl;
  cin>>n>>m;
  vector <ll> v=factoring(m);
  rep(i,v.size()){
    
    rep(j,n-1) {
      ans=ans*(v[i]+1+j);
      ans=ans%MOD;
    }
    //cout<<":"<<ans<<endl;
    //cout<<":"<<(factorial(n-1))<<endl;

    ans=ans/(factorial(n-1));
    //cout<<ans<<endl;

    ans=ans%MOD;

  }
  cout<<ans<<endl;
  return 0;
}
