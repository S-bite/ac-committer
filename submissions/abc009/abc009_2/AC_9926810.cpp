#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
  	cin>>n;
  	map<int,bool> mp;
  	vector<int> v;
  	for(int i=0;i<n;i++){
 		int t;
      	cin>>t;
    	if (mp[t]==false){
        	mp[t]=true;
          	v.push_back(t);
        }
    }
	sort(v.begin(),v.end(),greater<int>());
  	cout<<v[1]<<endl;
	return 0;
}
