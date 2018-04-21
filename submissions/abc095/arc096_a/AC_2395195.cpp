#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  if (A+B<2*C) {
    cout<<A*X+B*Y<<endl;
    return 0;
  }
  int q=(X>Y)? (X-Y)*min(A,2*C) : (Y-X)*min(B,2*C);
 cout<<min(X,Y)*(2*C)+q <<endl;
  return 0;
}
