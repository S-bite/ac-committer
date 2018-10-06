#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for (int i=0;i<(int)(n);i++)
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    if (m%n==0) {
      cout<<(m/n)<<endl;
      return 0;
    }
    for (int i=m/n;i>0;i--){
      if ((m-i*(n-1))%i==0){
        cout<<i<<endl;
        return 0;
      }
    }
    return 0;
}
