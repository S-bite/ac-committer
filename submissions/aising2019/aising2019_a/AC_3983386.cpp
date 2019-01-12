#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define rep(i,n) for(ll i=0;i<(n);i++)
using namespace std;

int main(){
    ll n,h,w;
    cin>>n>>h>>w;
    cout<<(1+n-w)*(1+n-h)<<endl;
    return 0;
}