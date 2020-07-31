#include<bits/stdc++.h>
using namespace std;
int main(){
  map<int,int> mp;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
  	int t;
    cin>>t;
    mp[t]++;
  }
  int x=-1,y=-1;
  for(int i=1;i<=n;i++){
  	if(mp[i]==2){
    	x=i;
    }
    if(mp[i]==0){
    	y=i;
    }
  }
  if(x==-1){
  	cout<<"Correct"<<endl;
  }else{
  	cout<<x<<" "<<y<<endl;
  }
  return 0;
}