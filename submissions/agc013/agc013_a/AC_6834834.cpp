#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#define MOD (ll)(1e9+7)
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    rep(i,n) cin>>a[i];
    int ans=0;
    int diff=0;
    rep(i,n-1){
        if (diff==0){
            if (a[i]<a[i+1]){
                diff=1;
            }else if (a[i]>a[i+1]){
                diff=-1;
            }
        }else if (diff==1){
            if (a[i]>a[i+1]){
                diff=0;
                ans++;
            }
        }else{
            if (a[i]<a[i+1]){
                diff=0;
                ans++;
            }
        }
    }
    cout<<ans+1<<endl;
    return 0;
}
