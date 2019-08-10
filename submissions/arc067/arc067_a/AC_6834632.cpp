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
    vector<int> prime;
    prime.push_back(2);
    rep(i,3,1000){
        bool f=true;
        rep(j,prime.size()){
            if (i%prime[j]==0){
                f=false;
                break;
            }
        }
        if (f){
            prime.push_back(i);
        }
    }
    int n;
    cin>>n;
    map<int,int> mp;
    for (int i=n;i>=1;i--){
        int p=1;
        int now=i;
        for (int p:prime){
                while (now%p==0){
                    mp[p]++;
                    now/=p;
                    }
                
            p++;
        }
    }
    mp[1]=0;
    ll ans=1;
    for (auto x: mp){
        ans*=x.second+1;
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}
