#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
string s;
cin>>s;
bool f=true;
int siz;
while (f){
  f=false;
  string t;
  siz=s.size();
  rep(i,siz){
    if((s[i]=='S' and s[min(i+1,siz-1)]=='S') or (s[i]=='T' and s[max(i-1,0)]=='T')) {
      t+=s[i];
    }else  f=true;

  }
  s=t;
}
cout<<siz<<endl;
return 0;
}
