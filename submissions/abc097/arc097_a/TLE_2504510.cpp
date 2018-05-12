#include<bits/stdc++.h>

using namespace std;
void update(vector<string> s,string t){
  for (int i =0;i<5;i++){
    if(s[i]>t){
      auto tmp=s[i];
      s[i]=t;
      t=tmp;
    }
  }
}

int main(){
vector<string> q;
//sort(q.begin(),q.end());
string s;
getline(cin,s);
int x;
cin>>x;
for (int i =0; i<s.size()+1;i++){
  for (int j=1;j<s.size()-i+1;j++){
    if (find(q.begin(),q.end(),s.substr(i,j))==q.end()){
    q.push_back(s.substr(i,j));}
  }
}
sort(q.begin(),q.end());
cout<<q[x-1]<<endl;
return 0;
}
