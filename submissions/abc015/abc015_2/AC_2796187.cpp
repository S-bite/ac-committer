#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int m=0;
  int n=0;
  for(int i=0;i<N;i++){
    int tmp;
    cin>>tmp;
    if(tmp!=0){
      m+=1;
      n+=tmp;
    }
  }
  cout<<(n+m-1)/m<<endl;

}
