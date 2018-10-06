#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for (int i=0;i<(int)(n);i++)
using namespace std;
int main(){
    int n;
    cin>>n;
    int x[n],y[n],h[n];
    rep(i,n){
      cin>>x[i]>>y[i]>>h[i];
    }
    rep(cx,101)rep(cy,101){
      bool f=true;
      int ch,i=0;
      while(h[i]==0)i++;
      ch=h[i]+abs(cx-x[i])+abs(cy-y[i]);
      for(int i=0;i<n;i++){
        if(h[i]!=max(ch-abs(cx-x[i])-abs(cy-y[i]),0)){
          f=false;
          break;
        }
      }
      if(f) {
        cout<<cx<<" "<<cy<<" "<<ch<<endl;
        return 0;
      }
    }

    return 0;
}
