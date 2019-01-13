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
    rep(i,s.size()){
        if (s[i]==k[np]) {
            if (use==1) use=2;
            np++;
            }
        else {
            if (use==0){
                use=1;
            }
            if(use==2){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    if (np==k.size())
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
 
    return 0;
}