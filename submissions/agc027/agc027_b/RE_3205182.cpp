#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
#define INF 1ll<<60
using namespace std;
ll sq(ll a){
  return a*a;
}
ll dfs(ll s,ll nc,int n,int nn,vector<ll> a,vector<bool> chk,ll x,ll k){
  //cout<<"k:"<<k<<",nc:"<<nc<<",nn:"<<nn<<",s:"<<s<<endl;
  //cout<<endl;
  if (nc>=s) return s;
  int next=-1,last=-1;
  for (int i=nn-1;i>=0;i--){
    if(chk[i]){
      if (last==-1) last=i;
      if (i<nn){next=i;break;}

    }

  }
  //cout<<"n:"<<next<<endl;

  if (next==-1) return (nc+a[nn]*sq(k+1)+x);
  chk[next]=false;
  nc+=sq(k+1)*(a[nn]-a[next]);
  ll lmin=dfs(s,nc+x,n,next,a,chk,x,k+1);
  chk[next]=true;
  nc+=sq(k+1)*a[next]+x+a[last]+x;
  chk[last]=false;
  return min(lmin,dfs(lmin,nc,n,last,a,chk,x,1));
}
int main(){
  int n,x;
  cin>>n>>x;
  vector<ll> a;
  rep(i,n){
    int t;
    cin>>t;
    a.push_back(t);
  }
  vector<bool> chk;
  rep(i,n){
    chk.push_back(true);
  }
  chk[n-1]=false;
  cout<<dfs(INF,a[n-1]+x,n,n-1,a,chk,x,1)<<endl;
  return 0;
}
//19999999983
//19999999981
