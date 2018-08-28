#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
int main(){
	int h,w,n;
	cin>>h>>w>>n;
	int a[n];
	rep(i,n) cin>>a[i];
	int ans[h][w];
	int c=0,index=0,len=0;
	rep(i,h)rep(j,w){
		ans[i][j]=c+1;
		a[c]--;
		if(a[c]==0) c++;
	}
	rep(i,h){
		if (i%2==0) reverse(ans[i],ans[i]+w);
		rep(j,w) cout<<ans[i][j]<<((j==w-1)?"":" ");
		cout<<endl;
	}
	return 0;
}
