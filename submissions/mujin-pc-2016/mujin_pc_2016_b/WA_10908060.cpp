#include<bits/stdc++.h>
#define lld long double
using namespace std;
int main(){
	int a,b,c;
  	cin>>a>>b>>c;
  	lld ans=acos(-1)*(a+b+c)*(a+b+c);
  	if (a>b+c){
    	ans-=acos(-1)*(a-b-c)*(a-b-c);
    }
  	cout<<fixed<<setprecision(18)<<ans<<endl;
	return 0;
}