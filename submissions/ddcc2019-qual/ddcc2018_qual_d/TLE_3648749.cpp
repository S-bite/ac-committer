#include<bits/stdc++.h>
#define MAX 1000000000000ll
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;
int numofbits(ll bits)
{
    int num  = 0;

    for ( ; bits != 0 ; bits &= bits - 1 ) {
        num++;
    }

    return num;
}

bool check(int a[29],ll n){
    rep(i,29){
        ll sum=0,t=n;
        while (t!=0){
            sum+=t%(i+2);
            t/=i+2;
        }
        if (sum!=a[i]) return false;
    }
    return true;
}
int main(){
    int a[29];
    rep(i,29) cin>>a[i];
    if(a[0]>=40) {
        cout<<"invalid"<<endl;
        return 0;
    }
    for(ll i=1ll<<(a[0]+1)-1;i<=MAX;i++){
        if (numofbits(i)!=a[0]) continue;
        if(check(a,i)){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"invalid"<<endl;
    return 0;    
}