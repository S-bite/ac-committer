#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
int main(){
	int n;
	cin>>n;
	int a[2*n];
	rep(i,2*n) cin>>a[i];
	sort(a,a+2*n);
	int ans=0;
	rep(i,2*n){ans+=a[i];i++;}
	cout<<ans<<endl;
	return 0;
}
