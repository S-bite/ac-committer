#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int A,B;
	cin>>A>>B;
	int ans=log2l(B/A);
//	if(ans-log2(B/A)==0) cout<<
	cout<<ans+1<<endl;
	return 0;
}