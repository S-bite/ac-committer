#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;
int main(){
  int q;
  cin>>q;
  rep(i,q){
    int a,b,c;
    cin>>a>>b>>c;
    if((a*100+b*10+c)%2==1){
      cout<<"No"<<endl;
      continue;
    }
    int tapi=(a*100+b*10+c)/2;
    tapi-=min(100*(tapi/100),a*100);
    tapi-=min(10*(tapi/10),b*10);
    tapi-=min(tapi,c);
    if (tapi==0){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
  return 0;
}
