#include<bits/stdc++.h>
#define lld long double
using namespace std;
int main(){
	int a[3];
  	cin>>a[0]>>a[1]>>a[2];
  	sort(a,a+3);
  	lld ans=acos(-1)*(a[0]+a[1]+a[2])*(a[0]+a[1]+a[2]);
  	if (a[2]>a[1]+a[0]){
    	ans-=acos(-1)*(a[2]-a[1]-a[0])*(a[2]-a[1]-a[0]);
    }
  	cout<<fixed<<setprecision(18)<<ans<<endl;
	return 0;
}