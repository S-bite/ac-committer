#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
int f(int n){
	if (n%2==0) return false;
	int ans=0;
	rep(i,n) if(n%(i+1)==0) ans++;
	return ans==8;
}
int main(){
	int n,ans=0;
	cin>>n;
	rep(i,n) if(f(i+1)) ans++;
	cout<<ans<<endl;
	return 0;
}
