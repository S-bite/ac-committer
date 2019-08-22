#include<bits/stdc++.h>
using namespace std;
int nowmin=50;
int dfs(int n,int now){
	if (now>=nowmin){
    	return 101010;
    }
	if (n==0){
    nowmin=min(nowmin,now);
      return now;
    }
  	return min({dfs(abs(n-1),now+1),dfs(abs(n-5),now+1),dfs(abs(n-10),now+1)});
}

int main(){
	int a,b;
  cin>>a>>b;
  cout<<dfs(abs(a-b),0)<<endl;
  return 0;
}