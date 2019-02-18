#include<bits/stdc++.h>
using namespace std;
long long collatz(long long n){
  if (n>=pow(10,16)) return 0;
	if (n%2==0) return n/2;
  else return 3*n+1;
}
int main(){
	long long  ans=1789997546303;
	int n;
  cin>>n;
  for (int i=0;i<1000-n;i++){
  ans=collatz(ans);}
  cout<<ans<<endl;
  return 0;
}
