#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(int)(n);i++)
#define INF (1<<30)
#define ll long long
using namespace std;
ll f(vector<int> a,vector<ll>s,int t){
  int e=a.size();
  int n=e/3;

  sort(&a[0],&a[t]);
  sort(&a[t],&a[e],greater<int>());
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
  int n;
  cin>>n;
  vector<int> a
  vecotr<ll>s;
  s.push_back(0);
  rep(i,3*n){int t; cin>>t; a.push_back(t);s.push_back(s.back()+t);}
  ll  ans=-INF;//f(a,s,3);
  for (int i=n;i<=2*n;i++) ans=max(ans,f(a,s,i));
    cout<<ans<<endl;;
  return 0;
}
