#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
int main(){
    int x;
    cin>>x;
    ll ans=0;
    ll now=0;
    ll i=1;
    while (now<x){
        now+=i;
        i++;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
