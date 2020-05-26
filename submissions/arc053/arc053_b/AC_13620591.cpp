#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
  	cin>>s;
  	map<char,int> mp;
  	for (auto &&c:s)mp[c]++;
  	int core=0;
  	int cover=0;
  	for (char c='a';c<='z';c++){
    	core+=mp[c]%2;
      	cover+=mp[c]/2;
    }
  	if (core==0){
    	cout<<cover*2<<endl;
    }else{
    	cout<<2*(cover/core)+1<<endl;
    }
  	return 0;
}