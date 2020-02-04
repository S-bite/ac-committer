#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
  	cin>>n;
  	vector<int> p(n),a(n),b(n);
  	for(int i=0;i<n;i++) p[i]=i+1;
  	for(int i=0;i<n;i++) cin>>a[i];
  	for(int i=0;i<n;i++) cin>>b[i];
   	int x,y;
  	int cnt=0;
  	do{
      if (a==p) x=cnt;
      if (b==p) y=cnt;
      cnt++;
    }while (next_permutation(p.begin(),p.end()));
  	cout<<abs(x-y)<<endl;
}