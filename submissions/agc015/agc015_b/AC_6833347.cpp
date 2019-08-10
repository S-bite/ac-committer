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
    string s;
    cin>>s;
    ll ans=0;
    rep(i,s.size()){
        if (s[i]=='U'){
            ans+=2*i+(s.size()-1-i);
        }else{
            ans+=i+2*(s.size()-1-i);     
        }
    }
    cout<<ans<<endl;
    return 0;
}
