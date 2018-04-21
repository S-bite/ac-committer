#include<bits/stdc++.h>
using namespace std;
int main(){
  int price=700;
  string s;
  cin>>s;
  for (int i=0;i<3;i++){
    if( char(s[i])==char('o')) price+=100;
  }
  cout<<price<<endl;
  return 0;
}
