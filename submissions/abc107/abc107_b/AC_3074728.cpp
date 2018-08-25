#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  int _h=h;
  string tmp="";
  for (int i=0;i<_h;i++){
    string s;
    cin>>s;
    if (s.find('#')!=string::npos) {tmp+=s;}else{h-=1;}
  }
  //cout<<tmp<<endl;
  //cout<<h<<endl;
  string ans="";
  for (int i=0;i<w*h;i++){
    string t="";
    for (int j=0;j<h;j++) t+=tmp[j*w+i%(w)];
  //  cout<<t<<endl;
    if (t.find('#')!=string::npos) ans+=tmp[i];
    if (i%w==w-1 and i+w-1<=h*w) ans+="\n";
  }
  cout<<ans<<endl;
  return 0;
}
