#include <bits/stdc++.h>
#define ll long long
#define INF 1<<20
using namespace std;
int main(){
  int N,K;
  cin>>N>>K;
  int lc[N]={},rc[N]={},a=1,b=1;

//  for (int i=0;i<N;i++) {lc[i]=INF;rc[i]=INF;}
  for (int i=0;i<N;i++){
    int t;
    cin>>t;
    if (t<0) {lc[a]=abs(t);a++;}
    else {rc[b]=abs(t);b++;}
  }
    for(int i=1;2*i<a;i++){
//      cout<<lc[i]<<","<<lc[a-i]<<endl;

      int tmp=lc[i];
      lc[i]=lc[a-i];
      lc[a-i]=tmp;
  //    cout<<lc[i]<<","<<lc[a-i]<<endl;

    }
    //cout<<a<<","<<b<<endl;
    //for(int i=0;i<a;i++)cout<<lc[i]<<endl;
    //cout<<endl;
    //for(int i=0;i<b;i++)cout<<rc[i]<<endl;
    int only_left;
    if (K<a) only_left=lc[K];else only_left=INF;

    int only_right;
    if (K<b) only_right=rc[K];else only_right=INF;

    int left_right=INF;
    for (int i=1;i<K;i++){
      if (i>=a or K-i>=b)continue;
      left_right=min(left_right,lc[i]+lc[i]+rc[K-i]);
    }

    int right_left=INF;
    for (int i=1;i<K;i++){
      if (i>=b or K-i>=a)continue;
      right_left=min(right_left,rc[i]+rc[i]+lc[K-i]);
    }
    //cout<<only_left<<endl;
    //cout<<only_right<<endl;
    //cout<<right_left<<endl;
    //cout<<left_right<<endl;
    cout<<min({only_left,only_right,right_left,left_right})<<endl;


  return 0;
}
