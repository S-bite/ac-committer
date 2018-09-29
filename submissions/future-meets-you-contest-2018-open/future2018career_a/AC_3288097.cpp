#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for (ll i=0;i<(ll)(n);i++)
#define fir first
#define sec second
using namespace std;
struct op{
    int v;
    int s;
    int e;
    int a;
    int i;
    int len;
    bool operator<( const op& right ) const {
    return  v < right.v ;
}
};
void p(int i, int j,int k,int l,int v){
  cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<v<<endl;
  return ;
}

int main(){
  int n,k;
  cin>>n>>k;
  int a[n];
  vector<op>b;
  vector<op>c;
  rep(i,n) {
    cin>>a[i];
    op d={a[i]-i-1,i+1,i+1,a[i],i+1,0};
    if (i>0){
      op old=b.back();
      if (old.v>0 and d.v>0){
        int v2=min(d.v,old.v);
        op d2={v2,i,i+1,-1,-1,2};
        c.push_back(d2);
      }else if(old.v<0 and d.v<0){
        int v2=max(d.v,old.v);
        op d2={v2,i,i+1,-1,-1,2};
        c.push_back(d2);
      }
    }
    b.push_back(d);
    }
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
  vector <int> used;
  rep(i,k){
    if(c.size()<2 and b.size()<2) cout<<"1 1 2 2 0"<<endl;
    //int bv=minv(abs(b.back().v),abs(b.front().v);
    if ((find( used.begin(),used.end() , c.back().s )!=used.end()) or (find( used.begin(),used.end() , c.back().e )!=used.end()) ){
      //cout<<c.back().s<<" "<<c.back().e<<endl;
      c.erase(c.end()-1);
      i--;
      continue;
    }
    if ((find( used.begin(),used.end() , c.front().s )!=used.end()) or (find( used.begin(),used.end() , c.front().e )!=used.end()) ){
    //  cout<<c.front().s<<" "<<c.front().e<<endl;

      c.erase(c.begin());
      i--;
      continue;
    }
    if ((find( used.begin(),used.end() , b.back().s )!=used.end())){
      //cout<<c.back().s<<" "<<c.back().e<<endl;
      b.erase(b.end()-1);
      i--;
      continue;
    }
    if ((find( used.begin(),used.end() , b.front().s )!=used.end())){
    //  cout<<c.front().s<<" "<<c.front().e<<endl;
      b.erase(b.begin());
      i--;
      continue;
    }
    int bv=min(abs(b.back().v),abs(b.front().v));
    int cv=min(abs(c.back().v),abs(c.front().v));
    if (2*cv>bv){
    p(c.back().s,c.back().e,c.front().s,c.front().e,cv);
    //cout<<c.size()<<endl;
    used.push_back(c.back().s);
    used.push_back(c.back().e);
    used.push_back(c.front().s);
    used.push_back(c.front().e);
    c.erase(c.begin());
    c.erase(c.end()-1);
  }else{
    p(b.back().s,b.back().e,b.front().s,b.front().e,bv);
    //cout<<c.size()<<endl;
    used.push_back(b.back().s);
    used.push_back(b.front().s);
    b.erase(b.begin());
    b.erase(b.end()-1);
  }

  }
  return 0;
}
