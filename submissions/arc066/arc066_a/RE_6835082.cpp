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
    map<int,int> mp,tmp;
    rep(i,n){
        mp[abs((n-1-i)-i)]++;
    }
    tmp=mp;
    int a[n];
    rep(i,n){
        cin>>a[i];
        if (tmp[a[i]]==0){
            cout<<0<<endl;
            return 1;
        }
        tmp[a[i]]--;
    }
    ll ans=1;
    rep(i,n/2){
        ans*=2;
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}
