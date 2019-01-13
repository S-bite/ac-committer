#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define rep(i,n) for(ll i=0;i<(n);i++)
using namespace std;

int main(){
    int a[4];
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    sort(a,a+4);
    if(a[0]==1 and a[1]==4 and a[2]==7 and a[3]==9) cout<<"YES"<<endl;
    else cout<<"NO" <<endl;
      return 0;
}