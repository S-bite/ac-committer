#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
    cin>>a>>b;
	if (a==b) cout<<"Draw"<<endl;
  	else if (a==1 or a>b) cout<<"Alice"<<endl;
  	else cout<<"Bob"<<endl;
  return 0;
}
