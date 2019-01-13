#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define rep(i,n) for(ll i=0;i<(n);i++)
#define MOD (1000000007ll)
using namespace std;

int main(){
    ll n,m;
    cin>>n>>m;
    ll a[n];
    ll b[m];
    bool chka[n];
    bool chkb[m];
    rep(i,n) {
        chka[i]=false;
        cin>>a[i];
    }
    rep(i,m){
        chkb[i]=false;
        cin>>b[i];
    }
    sort(a,a+n,greater<ll>());
    sort(b,b+m,greater<ll>());
    if(a[0]!=b[0]){
        cout<<0<<endl;
        return 0;
    }
    ll free[n]={};
    ll ans=1;
    rep(i,n) free[i]=m;
    for (ll i=m*n;i>0;i--){
        ll px=-1,py=-1;
        rep(y,n){
            if (i>a[y]) break;
            py=y;
        }
        rep(x,m){
            if (i>b[x]) break;
            px=x;
        }
        if (px==-1 or py==-1) {
            cout<<0<<endl;
            return 0;
        }
        if(b[px]==i and a[py]==i) {
            chka[py]=true;
            chkb[px]=true;
            ans*=1;
            ans%=MOD;
        }else if (b[px]==i){
            chkb[px]=true;
            ans*=(py+1);
            ans%=MOD;
        }else if (a[py]==i){
            chka[py]=true;
            ans*=(px+1);
            ans%=MOD;
        }else{
            ll j=m*n-i;
            ans*=((px+1)*(py+1) -j );
            ans%=MOD;
        }

    }


    rep(i,n)if (chka[i]==false){
        cout<<0<<endl;
        return 0;
    }
    rep(i,m)if (chkb[i]==false){
        cout<<0<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;


}