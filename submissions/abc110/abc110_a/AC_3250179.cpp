#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;


int main(){
  int a[3];
  cin>>a[0]>>a[1]>>a[2];
  sort(a,a+3);

  cout<<a[2]*10+a[1]+a[0]<<endl;
    return 0;
}
