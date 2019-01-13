#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define rep(i,n) for(ll i=0;i<(n);i++)
using namespace std;

int main(){
    string k="keyence";
    int np=0;
    int use=0;
    string s;
    cin>>s;
    rep(i,k.size()){
        string hk=k.substr(0,i);
        string tk=k.substr(i);
        int hind=s.find(hk);
        int tind=s.rfind(tk);
    
        if(hind<tind and ((hind!=0 and hind+i==tind) or (tind!=0 and hind==0 and hind+i==tind) or (hind==0 and tind+k.size()-i==s.size()))) {
            cout<<"YES"<<endl;
            return 0;
            }
    }
    cout<<"NO"<<endl;
 
    return 0;
}