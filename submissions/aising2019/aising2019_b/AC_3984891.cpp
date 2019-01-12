#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define rep(i,n) for(ll i=0;i<(n);i++)
using namespace std;

int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    ll p[n];
    rep(i,n) cin>>p[i];
    ll x=0,y=0,z=0;
    rep(i,n){
        if(p[i]<=a) x++;
        else if (p[i]<=b) y++;
        else z++;
    }
    cout<<min({x,y,z})<<endl;
    return 0;
}