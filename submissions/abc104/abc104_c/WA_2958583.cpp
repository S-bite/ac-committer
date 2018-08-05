#include<bits/stdc++.h>
using namespace std;
int main(){
  int D,G;
  cin>>D>>G;
  int p[D],c[D];
  for(int i=0;i<D;i++)cin>>p[i]>>c[i];
  pair<double, pair <int,int > > a[D];
  for(int i=0;i<D;i++){
    a[i].first=(((double)(i+1)*100*p[i]+c[i])/p[i]);
    a[i].second.first=(i+1)*100*p[i]+c[i];
    a[i].second.second=i;
  }
  bool used[D]={false};
  sort(a,a+D,greater<pair<double, pair <int,int> > >());
  int ans=0;
  for(int i=0;i<D;i++){
    if (G>=a[i].second.first){G-=a[i].second.first;ans+=p[a[i].second.second];used[a[i].second.second]=true;}
    else break;
  }
  if(G==0){cout<<ans<<endl; return 0;}
  int _min=999;
  for(int i =0;i<D;i++){
    if (used[i]) continue;
    if(G<=(1+i)*100*(p[i]-1)) {_min=min(_min,(G+(1+i)*100-1)/((1+i)*100));}
    else if(G<=(i+1)*100*p[i]+c[i]) {_min=min(_min,p[i]);}
  }
  cout<<_min+ans<<endl;
}
