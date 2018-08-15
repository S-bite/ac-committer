#include<bits/stdc++.h>

using namespace std;
int standbits(int bits){
  int ret=0;
  for(;bits!=0;bits&=bits-1)ret++;
  return ret;
}
int eval(int s,vector<int> F, vector<vector<int> > P,int N){
  int ret=0;
  for (int i=0;i<N;i++){
    //cout<<bitset<10>(F[i])<<endl<<standbits(s&F[i])<<endl;;
    ret+=P[i][standbits(s&F[i])];
  }
  return ret;
}


int main(){
  //cout<<standbits(011111101LL)<<endl;
  int N;
  cin>>N;
  vector<int>F;
  for(int i=0;i<N;i++){
    F.push_back(0);
    for(int j=0;j<10;j++){
        int t;
        cin>>t;
        F[i]+=t;
        F[i]=F[i]<<1;
    }
    F[i]=F[i]>>1;
  }
  vector< vector<int> > P;
  for(int i=0;i<N;i++){
    P.push_back({});
    for(int j=0;j<11;j++){
      int t;
      cin>>t;
      P[i].push_back(t);
    }


  }
  int ans=-1000000001;
//  cout<<ans<<endl;
  for (int i=1;i<1024;i++){
    ans=max(ans,eval(i,F,P,N));
  }
  cout<<ans<<endl;
  return 0;
}
