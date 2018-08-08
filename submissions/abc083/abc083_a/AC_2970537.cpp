#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C,D;
  cin>>A>>B>>C>>D;
  if(A+B>C+D) cout<<"Left"<<endl;
  if(A+B<C+D) cout<<"Right"<<endl;
  if(A+B==C+D) cout<<"Balanced"<<endl;
  return 0;
}