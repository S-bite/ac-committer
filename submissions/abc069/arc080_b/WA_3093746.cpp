#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
int main(){
	int h,w,n;
	cin>>h>>w>>n;
	int a[n];
	rep(i,n) cin>>a[i];
	string s[h];
	s[0]="";
	int c=0,index=0,len=0;
	while(a[n-1]!=0){
		s[index]+=to_string(c+1)+" ";
		len++;
		a[c]--;
		if (a[c]==0) {c++;}
		if (len==w) {index++;len=0;}
	}
	rep(i,h){
		s[i].erase(s[i].size()-1);
		if (i%2==1) reverse(s[i].begin(),s[i].end());
		cout<<s[i]<<endl;
	}
	return 0;
}
