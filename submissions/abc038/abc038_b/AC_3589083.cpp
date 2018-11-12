#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define vec vector
using namespace std;
int main(){
    int h1,w1,h2,w2;
    cin>>h1>>w1>>h2>>w2;
    if ( h1==h2 or w1==w2 or h1==w2 or w1==h2 ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}