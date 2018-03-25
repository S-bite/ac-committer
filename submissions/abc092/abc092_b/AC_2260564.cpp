#include <iostream>
using namespace std;
int main(){
  int n,d,x,c=0;
  cin>>n;
  cin>>d>>x;
  int a[100];
  for (int i=0;i<n;i++){
    int tmp;
    cin>>tmp;
    a[i]=tmp;
  }
    for (int i=0;i<n;i++){
      int k=0;
      while(true){
        if (a[i]*k+1<=d) c++;else break;
        k++;
      }
    }

  cout<<c+x<<endl;
}
