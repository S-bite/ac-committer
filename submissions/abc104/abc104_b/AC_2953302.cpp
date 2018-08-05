#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  if (s[0]!='A') {cout<<"WA"<<endl;return 0;}
  if ((int)s[1]-(int)'Z'<=0) {cout<<"WA"<<endl;return 0;}
  int c=0;
  for (int i=2;i<s.size()-1;i++){
    if(s[i]=='C') {c++;continue;}
    if ((int)s[i]-(int)'Z'<=0) {cout<<"WA"<<endl;return 0;}
  }
  if ((int)s[s.size()-1]-(int)'Z'<=0) {cout<<"WA"<<endl;return 0;}
  if(c==1) cout<<"AC"<<endl;
  else cout<<"WA"<<endl;
}
