#include <iostream>
using namespace std;
int check(int n,int A, int B){
	int t=0;
	do{t+=n%10;
	}while(n/=10);
	return (A<=t and t<=B);
}

int main() {
	int N,A,B,ans=0;
	cin>>N>>A>>B;
	for(int i=1;i<=N;i++){
		ans+=check(i,A,B)?i:0;
	}
	cout<<ans<<endl;
	return 0;
}