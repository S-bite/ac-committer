#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;
bool enough(vector<int>h,int T,int a,int b){
  int d=a-b;
  int t=0;
  rep(i,h.size()){
    if (h[i]-b*T>0){
      t+=(h[i]-b*T+d-1)/d;
    }
  }
  return t<=T;
}
int main(){
  int n,a,b;
  cin>>n>>a>>b;
  vector<int>h;
  rep(i,n){
    int t;
    cin>>t;
    h.push_back(t);
  }
  int upper=(1<<30)/b+1,lower=0;
  while (upper!=lower+1){
  //  cout<<upper<<","<<lower<<endl;
    int T=(upper+lower)/2;
    if(enough(h,T,a,b)){
      upper = T;
    }else lower=T;
  }
  cout<<upper<<endl;
}
