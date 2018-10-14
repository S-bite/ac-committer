#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(long long i=0;i<(ll)(n);i++)
#define fir first
#define sec second

using namespace std;
int main(){
  int n,x;
  cin>>n>>x;
  pair<int,int> d[n];
  rep(i,n)cin>>d[i].sec>>d[i].fir;
  sort(d,d+n,greater<pair<int,int> >());
  d[0].sec+=x;
  ll ans=0;
  rep(i,n)ans+=d[i].fir*d[i].sec;
  cout<<ans<<endl;
  return 0;
}
