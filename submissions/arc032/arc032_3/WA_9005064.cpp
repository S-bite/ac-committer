#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
  	cin>>n;
    vector<pair<int,int>> v(n);
  	for(int i=0;i<n;i++){
    	cin>>v[i].second>>v[i].first;
    }
  	sort(v.begin(),v.end());
  	int ans=0;
    int cur=0;
  	for(int i=0;i<n;i++){
    	if (v[i].second>=cur){
        	ans++;
          	cur=v[i].first;
        }
    }
  	cout<<ans<<endl;
  	return 0;
}