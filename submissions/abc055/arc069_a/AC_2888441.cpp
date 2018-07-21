#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int N,M;
    cin>>N>>M;
    if(M>=2*N) cout<<(N+(M-2*N)/4)<<endl;
    else cout<<(M/2)<<endl;
}
