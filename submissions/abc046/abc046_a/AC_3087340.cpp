#include<bits/stdc++.h>
using namespace std;
int main(){
  	int a[3];
  cin>>a[0]>>a[1]>>a[2];
  sort(a,a+3);
  int ret=1;
  if(a[0]!=a[1]) ret++;
  if (a[1]!=a[2] )ret++;
  cout<<ret<<endl;
	return 0;
}