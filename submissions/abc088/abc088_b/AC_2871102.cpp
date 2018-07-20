#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int a[N];
  for(int i=0;i<N;i++) cin>>a[i];
  sort(a,a+N,greater<int>());
  int ans=0;
  for(int i=0;i<N;i++)ans+=(i%2==0)?a[i]:-a[i];
  cout<<ans<<endl;
  return 0;
}
