#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define rep(i,n) for(ll i=0;i<(n);i++)
using namespace std;

int main(){
    string k="keyence";
    int np=0;
    string s;
    cin>>s;
    rep(i,s.size()){
        if(s[i]==k[np]){
            np=min(np+1,(int)k.size());
        }
    }
    if (np==k.size())cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}