#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
  	cin>>n;
  	map<string,int> mp;
  	for(int i=0;i<n;i++){
    	string t;
      	cin>>t;
      	mp[t]++;
    }
  	string ans;
  	int mnum=-1; 
  	for (auto x:mp){
    	if(x.second>mnum){
        	mnum=x.second;
          	ans=x.first;
        }
    }
  	cout<<ans<<endl;
  	return 0;
}
