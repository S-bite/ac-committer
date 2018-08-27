#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	cout<<(2*max({a,b,c})+2*min({a,b,c})-a-b-c)<<endl;
  return 0;
}
