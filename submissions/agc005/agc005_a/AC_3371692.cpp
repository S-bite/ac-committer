#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
string s;
cin>>s;
bool f=true;
int trest=0,srest=0;
rep(i,s.size()){
  if (s[i]=='T'){
    if(srest==0) trest++;
    else srest--;
  }else{
    srest++;
  }
}
cout<<(trest+srest)<<endl;
return 0;
}
