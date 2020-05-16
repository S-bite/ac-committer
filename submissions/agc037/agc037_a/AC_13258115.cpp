#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
  	cin>>s;
	int ans=0;
  	int cur=0;
  	string t="";
  	string prev="";
  	while(cur<s.size()){
    	t+=s[cur];
		cur++;
    	if (t!=prev){
			prev=t;
          	t="";
          	ans++;
        }
    }
  	cout<<ans<<endl;
	return 0;
}