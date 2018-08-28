#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
struct Union{
  Union *par;
  int val=-1;
  int rank=1;
};

Union *root(Union *t){
  if (t->par==t) return t;
  else {
		t->par=root(t->par);
		return t->par;
	}
}

void unite (Union *a,Union *b){
  if (a->rank>b->rank) root(b)->par=root(a);
  else {
    root(a)->par=root(b);
    if (a->rank==b->rank) b->rank++;
  }

}
bool same(Union *a,Union *b){
  return root(a)==root(b);
}

int main(){
  int n,k,l;
  cin>>n>>k>>l;
  Union r[n],t[n];
  rep(i,n){r[i].par=&r[i];t[i].par=&t[i];}
	rep(i,k){
		int a,b;
		cin>>a>>b;
		unite(&r[a-1],&r[b-1]);
	}
	rep(i,l){
		int a,b;
		cin>>a>>b;
		unite(&t[a-1],&t[b-1]);
	}
	rep(i,n){
    int ans=0;
    rep(j,n){
		if(same(&r[i],&r[j]) and same(&t[i],&t[j])) ans++;
	}
  cout<<ans<<((i==n-1)?"":" ");
}
cout<<endl;
	return 0;
}
