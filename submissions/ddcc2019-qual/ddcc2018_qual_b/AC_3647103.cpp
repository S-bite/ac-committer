#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main(){
    int n;
    cin>>n;
    if (n%2==0)cout<<2*((n/2-1)*n/2)<<endl;
    else cout<<(2*((n/2-2)*(n/2-1))+4*(n/2-1)+1)<<endl;
    
    return 0;    
}