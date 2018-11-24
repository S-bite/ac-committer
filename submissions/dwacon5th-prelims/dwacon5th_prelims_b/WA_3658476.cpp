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
    /*for(ll i=k-1;i<(n*(n+1))/2;i++){
        ll ans=p[i];
        int rk=k-1;
        for(ll j=0;j<i;j++){
            cout<<ans<<endl;
            if ((ans&p[j])==ans) {rk--;}
            if(rk==0){
                cout<<ans<<endl;
                return 0;
            }
        }
    }
    cout<<0<<endl;*/
    ll ans=p[0];
    rep(i,k) ans&=p[i];
    cout<<ans<<endl;
    return 0;
}