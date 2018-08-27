#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
int main(){
  	int n,s,t;
  cin>>n>>s>>t;
	int w=0;
		int ans=0;
		rep(i,n){
			int j;
			cin>>j;
			w+=j;
			if(s<=w and w<=t) ans++;
		}
		cout<<ans<<endl;
  return 0;
}
