#include<bits/stdc++.h>
using namespace std;
struct Union{
  Union *par;
  int val=-1;
  int rank=1;
};

Union *root(Union *t){
  if (t->par==t) return t;
  else return root(t->par);
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
  Union u[13];
  for(int i=0;i<13;i++) u[i].par=&u[i];
  unite(&u[1],&u[3]);
  unite(&u[1],&u[5]);
  unite(&u[1],&u[7]);
  unite(&u[1],&u[8]);
  unite(&u[1],&u[10]);
  unite(&u[1],&u[12]);
  unite(&u[6],&u[4]);
  unite(&u[9],&u[6]);
  unite(&u[11],&u[4]);
  int x,y;
  cin>>x>>y;
  if(same(&u[x],&u[y])) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;

}
