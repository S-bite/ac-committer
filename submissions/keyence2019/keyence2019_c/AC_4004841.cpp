#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define rep(i,n) for(ll i=0;i<(n);i++)
using namespace std;

int main(){
    ll n;
    cin>>n;
    ll a[n];
    ll b[n];
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    ll nsum=0;
    ll p[n]={};
    ll ip=0;
    ll ans=0;

    rep(i,n){
        if(a[i]<b[i]){
             nsum+=a[i]-b[i];
             ans++;
             }
        else {
            p[ip]=a[i]-b[i];
            ip++;
        }
    }
    sort(p,p+ip,greater<ll>());
    rep(i,ip){
        if(nsum>=0) break;
   
        nsum+=p[i];
        ans++;
    }
    if(nsum<0) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;


}