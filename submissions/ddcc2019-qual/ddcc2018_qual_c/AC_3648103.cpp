#include<bits/stdc++.h>
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;
ll powmod(int i){
    ll ret=1;
    rep(j,10)ret=(ret*i)%MOD;
    return ret;
}
int main(){
    int n;
    cin>>n;
    //int r=sqrt(n);
    ll ans=0;
    ll t=0;
    for (int i=1;i<=n;i++){
    int j=n/i;
    ll s=powmod(i)-t;
    if(s<0) s+=MOD;
    ans=(ans+s*powmod(j)%MOD)%MOD;
   // if (ans<0) cout<<"powmod(i)-t:"<<(powmod(i)-t)<<",powmod(j):"<<powmod(j)<<endl;
    t=powmod(i);
    }
    cout<<ans<<endl;
    return 0;    
}