#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
string s;
cin>>s;
bool contained[4]={false,false,false,false};
rep(i,s.size()){
  if (s[i]=='N') contained[0]=true;
  if (s[i]=='E') contained[1]=true;
  if (s[i]=='W') contained[2]=true;
  if (s[i]=='S') contained[3]=true;
}
if (contained[0]^contained[3]||contained[1]^contained[2]) cout<<"No"<<endl;
else cout<<"Yes"<<endl;
return 0;
}
