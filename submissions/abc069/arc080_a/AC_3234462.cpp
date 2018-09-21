#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;
int main(){
  int n;
  cin>>n;
  int four=0,even=0,odd=0;
  rep(i,n){
    int t;
    cin>>t;
    if(t%4==0) four++;
    else if (t%2==0) even++;
    else odd++;
  }
  if (even==0) cout<<((four>=odd-1)?"Yes":"No")<<endl;
  else cout<<((four>=odd)?"Yes":"No")<<endl;
  return 0;
}
