#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for (ll i=0;i<(ll)(n);i++)
using namespace std;
int main(){
  int n;
  cin>>n;
  pair<int,int> a[100020],b[100020];
  rep(i,100020){
    a[i].first=0;
    a[i].second=i;

    b[i].first=0;
    b[i].second=i;
  }
  rep(i,n){
    int t;
    cin>>t;
    if(i%2==0){
      a[t].first++;
    }else{
      b[t].first++;
    }
  }
  sort(a,a+100020,greater<pair<int,int> >());
  sort(b,b+100020,greater<pair<int,int> >());
  //cout<<a[0].second<<","<<b[0].second<<endl;
  if (a[0].second==b[0].second){
    cout<<min((n-a[0].first-b[1].first),(n-a[1].first-b[0].first))<<endl;;
  }else{
      cout<<(n-a[0].first-b[0].first)<<endl;
  }
  return 0;
}
