#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
  int h,w,ch,cw,n=0;
  string ans="";
  cin>>h>>w;
  bool c[w];
  rep(i,w)c[i]=false;
  rep(i,(h-1)*w){
    cw=i%w;
    ch=i/w;
  //  cout<<"b:"<<ch<<","<<cw<<endl;
    int t;
    cin>>t;
    if(c[cw])t++;
    if (t%2!=0) {ans+=to_string(ch+1)+" "+to_string(cw+1)+" "+to_string(ch+2)+" "+to_string(cw+1)+"\n";n++;}
    c[cw]=(t%2!=0);
  }
  bool f=false;
  rep(i,w-1){
    cw=i%w;

      int t;
      cin>>t;
      if(c[cw])t++;
      if(f)t++;
      if (t%2!=0) {ans+=to_string(h)+" "+to_string(cw+1)+" "+to_string(h)+" "+to_string(cw+2)+"\n";n++;}
      f=(t%2!=0);
  }
  cout<<n<<endl<<ans;
  return 0;
}
