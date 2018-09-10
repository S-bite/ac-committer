#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
	map<string,bool>mp;
  int n;
  cin>>n;
  char old='@';
  rep(i,n){
    string s;
    cin>>s;
    if (mp[s] or (old!='@' and s[0]!=old)) {cout<<"No"<<endl;return 0;}
    mp[s]=true;
    old=s[s.size()-1];
  }
  cout<<"Yes"<<endl;
  return 0;
}
