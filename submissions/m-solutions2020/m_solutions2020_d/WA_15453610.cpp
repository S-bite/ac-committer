#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n];
  for (int i=0;i<n;i++){
  	cin>>a[i];
  }
  int x=1000;
  int y=0;
  for (int i=0;i<n-1;i++){
    y=0;
    if (a[i]<a[i+1]){
      y=x/a[i];
      x%=a[i];
    }
  	x+=a[i+1]*y;
 	
  }
 
  cout<<x<<endl;

}