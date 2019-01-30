#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,ans=0;
  cin>>n;
  map<char,bool> mp;
  for (int i=0;i<n;i++){
  	char c;
    cin>>c;
    if (mp[c]!=true){
    	ans++;
      mp[c]=true;
    }
  }
  
  cout<<((ans==3)?"Three":"Four")<<endl;
return 0;
}
