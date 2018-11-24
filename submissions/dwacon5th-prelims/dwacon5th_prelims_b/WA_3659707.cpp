#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    ll a[n],s[n+1],p[(n*(n+1))/2];
    s[0]=0;
    rep(i,n){
     cin>>a[i];
     s[i+1]=s[i]+a[i];
    }
    ll c=0;
    for(int i=0;i<n;i++)
    for(int j=i+1;j<=n;j++){p[c]=s[j]-s[i];c++;}
    sort(p,p+(n*(n+1))/2,greater<ll>());
    ll ans=0;
    for(int i=30;i>=0;i--){
        ll b=1ll<<i;
        int r=0;
        for(ll j=0;j<(n*(n+1))/2;j++){
            if ((b&p[j])!=0) r++;

        }
        if (r>=k){
            ans+=1;
            for(ll j=0;j<(n*(n+1))/2;j++){
            if ((b&p[j])==0) p[j]=0;
        }
     }
        ans<<=1;
    }
    ans>>=1;
    cout<<ans<<endl;
    return 0;
}