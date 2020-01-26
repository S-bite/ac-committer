#include<bits/stdc++.h>
using namespace std;

bool isok(int n,map<int,bool> &mp){
	while(n!=0){
    	if (mp[n%10]==true){
        	return false;
        }
        n/=10;
    }
  return true;
}

int main(){
  	int n,k;
  	cin>>n>>k;
  	map<int,bool> mp;
  	for (int i=0;i<k;i++){
    	int t;
      	cin>>t;
      	mp[t]=true;
    }
  	int ans=n;
 	while (isok(ans,mp)==false) ans++;
  	cout<<ans<<endl;
    return 0;
}
