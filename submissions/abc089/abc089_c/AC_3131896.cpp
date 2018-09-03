#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
int main(){
  int N;
  cin>>N;
  ll a[26]={};
  rep(i,N){
    string s;
    cin>>s;
    a[(int)s[0]-'A']++;
  }
  ll ans=0;
  int t[5]={'M'-'A','A'-'A','R'-'A','C'-'A','H'-'A'};
  rep(i,5)rep(j,5)rep(k,5)if(i>j and j>k) ans+=a[t[i]]*a[t[j]]*a[t[k]];
  cout<<ans<<endl;
  return 0;
}
