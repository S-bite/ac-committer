#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define vec vector
using namespace std;
int main(){
    int h1,w1,h2,w2;
    cin>>h1>>w1>>h2>>w2;
    if (max(h1,w1)==max(h2,w2) or min(h1,w1)==min(h2,w2) ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}