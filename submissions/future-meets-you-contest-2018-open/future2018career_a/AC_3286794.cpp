#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for (ll i=0;i<(ll)(n);i++)
#define fir first
#define sec second
using namespace std;
void p(int i, int j,int k,int l,int v){
  cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<v<<endl;
  return ;
}

int main(){
  string NOOP="1 2 3 4 0";
  int n,k;
  cin>>n>>k;
  int a[n];
  pair<int,int>b[n];
  rep(i,n) {
    cin>>a[i];
    b[i]=make_pair(a[i]-i-1,i+1);
    }
  sort(b,b+n);
  rep(i,k){
    int high=n-i-1,low=i;
    int v=min(abs(b[high].fir),abs(b[low].fir));
    p(b[high].sec,b[high].sec,b[low].sec,b[low].sec,v);
  }
  return 0;
}
