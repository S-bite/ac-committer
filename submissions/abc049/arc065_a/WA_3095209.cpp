#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
	string s;
	cin>>s;
	reverse(s.begin(),s.end());

	while (s.size()!=0){

		if (s.substr(0,5)=="maerd" or s.substr(0,5)=="esare") s.erase(0,5);
		else if (s.substr(0,7)=="remaerd" or s.substr(0,7)=="reesare") s.erase(0,7);
		else break;
	}
	if (s.size()==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
