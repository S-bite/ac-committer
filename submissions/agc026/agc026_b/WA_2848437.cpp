#include<bits/stdc++.h>
using namespace std;
int rp(long long int a,long long int b){
  if(a==0 or b==0) return false;
  if(a%b==0) return(b==1)?true:false;
  return rp(b,a%b);
}
int main(){
  int T;
  cin>>T;
  long long int A,B,C,D;
  for(int i=0;i<T;i++){
    cin>>A>>B>>C>>D;
    long long int a=B-C; //x<C+aにできたら勝ち
    long long int d=D-B;
    long long int g=(A-C)%B;
    if(g==0)g=B;
    if(B>D){cout<<"No"<<endl;continue;}
    if(A<B){cout<<"No"<<endl;continue;}
    if(B<=D and C>=B){cout<<"Yes"<<endl;continue;}
    if (a==1){cout<<"Yes"<<endl;continue;}
  //  cout<<d<<","<<B<<endl;
  //  cout<<(rp(max(d,B),min(d,B)) ? "No":"Yes")<<endl;;
  bool f=false;
  long long int q=min(B+1,d+1);
  for(int j=0;j<q;j++){
    if(g<a){cout<<"No"<<endl;f=true;break;}
    g=(g+d)%B;
    if(g==0)g=B;
  }
  if(!f)cout<<"Yes"<<endl;
  }
}
/*14 10 7 11
15
16
17
7*/
/*
c=A;
while(c>0){
c-=B;
if(c<=C)c+=D;
}*/
