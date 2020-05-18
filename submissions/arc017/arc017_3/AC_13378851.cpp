#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
random_device rnd;
mt19937 mt(rnd());
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int IINF=1<<30;
const ll INF=1ll<<60;
const ll MOD = 1000000007;

int main(){
    int n,x;
    cin>>n>>x;
    int l,r;
    l=n/2;
    r=n-l;
    VI v(n);
    rep(i,n)
    {
        cin>>v[i];
    }
    map<int,int> mp;
    rep(i,1<<l){
        int cur=0;
        rep(j,l){
            if ((i>>j)&1){
                cur+=v[j];
            }
        }
        mp[cur]++;
    }
    ll ans=0;
    
    rep(i,1<<r){
        int cur=0;
        rep(j,r){
            if ((i>>j)&1){
                cur+=v[l+j];
            }
        }
        if (cur<=x){
            ans+=mp[x-cur];
        }
    }
    cout<<ans<<endl;
    return 0;
}

