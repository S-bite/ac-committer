#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for (ll i=0;i<(ll)(n);i++)
using namespace std;
#define IMP "impossible"
string dfs(vector<string> v, int depth,int pos,string move){
  if (v[depth][pos]=='x') return IMP;
  int h=v.size(),w=v[0].size();
  if (depth==h-1) return move;
  string ret=dfs(v,depth+1,pos,move+"S");
  if (ret==IMP) ret=dfs(v,depth+1,max(0,pos-1),move+"L");
  if (ret==IMP) ret=dfs(v,depth+1,min(w-1,pos+1),move+"R");
  return ret;
}
int main(){
  int h,w;
  cin>>h>>w;
  vector<string>v;
  rep(i,h){
    string s;
    cin>>s;
    v.push_back(s);
  }
  reverse(v.begin(),v.end());
  int pos=v[0].find("s");
  cout<<dfs(v,0,pos,"")<<endl;
  return 0;
}
