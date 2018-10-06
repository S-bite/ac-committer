#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for (ll i=0;i<(ll)(n);i++)
using namespace std;
int main(){
    int n,T;
    int ans=10000;
    cin>>n>>T;
    rep(i,n){
      int c,t;
      cin>>c>>t;
      if(t<=T) ans=min(ans,c);
    }
    if (ans==10000) cout<<"TLE"<<endl;
    else cout<<ans<<endl;
    return 0;
}
