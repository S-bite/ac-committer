#include<bits/stdc++.h>
using namespace std;
int main(){
	long double n,k;
  	cin>>n>>k;
  	long double ans=(1.0/n)*(1.0/n)*(1.0/n);
  	ans+=(1.0/n)*(1.0/n)*((k-1)/n)*3;
  	ans+=(1.0/n)*(1.0/n)*((n-k)/n)*3;
  	ans+=(1.0/n)*((k-1)/n)*((n-k)/n)*6;
  	cout<<fixed<<setprecision(18)<<ans<<endl;
}
