#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
int main(){
	int a[3],b[3];
	cin>>a[0]>>a[1]>>a[2];
	b[0]=a[0];
	b[1]=a[1];
	b[2]=a[2];
	map <int,int> m;
	sort(a,a+3,greater<int>());
	rep(i,3) m.insert(make_pair(a[i],i+1));
   rep(i,3)cout<<m[b[i]]<<endl;
  return 0;
}
