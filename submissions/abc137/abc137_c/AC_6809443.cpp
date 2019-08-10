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
    map<vector<char>,ll>mp;
    int n;
    cin>>n;
    rep(i,n){
    string s;
    cin>>s;
    vector<char> v;
    rep(j,s.size()){
            v.push_back(s[j]);
    }
    sort(ALL(v));
    mp[v]++;
    }
    ll ans=0;
    for (auto x: mp){
        ans+=x.second*(x.second-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}
