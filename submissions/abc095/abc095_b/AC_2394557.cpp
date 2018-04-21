#include<bits/stdc++.h>
using namespace std;
int main(){
  int cost_min=2048;
  int n,x;
  cin>>n>>x;
  for (int i=0;i<n;i++){
    int s;
    cin>>s;
    x-=s;
    if (s<cost_min) cost_min=s;
  }
  cout<<x/cost_min+n<<endl;
  return 0;
}
