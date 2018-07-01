#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  long long int l,h;
  l=1000000001;
  h=1;
  for (int i=0;i<N;i++){
    long long int t;
    cin>>t;
    l=min({t,l});
    h=max({t,h});
  }
  cout<<(h-l)<<endl;
}
