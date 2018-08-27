#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
int main(){
  pair <int,int> a[3];
	rep(i,3){
      int t;
      cin>>t;
      a[i]=make_pair(t,i+1);
    }
 	sort(a,a+3,greater<pair<int,int> >());
  rep(i,3)cout<<a[i].second<<endl;
  return 0;
}
