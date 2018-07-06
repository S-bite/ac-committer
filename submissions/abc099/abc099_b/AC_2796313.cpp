#include<bits/stdc++.h>
using namespace std;
int f(int n){
  return (n*(n+1))/2;
}
int main(){
int a,b;
cin>>a>>b;
cout<<f(b-a-1)-a<<endl;
}
