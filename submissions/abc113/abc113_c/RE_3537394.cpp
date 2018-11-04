#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define fir first
#define sec second

using namespace std;
struct city{
  int id;
  int year;
  int pref;
  int order;
};
bool compyear(city l, city r) {
    return l.year < r.year;
}
bool compid(city l, city r) {
    return l.id < r.id;
}

int main(){
    int n,m;
    cin>>n>>m;
    city cities[m];

    rep(i,m){
      int y,p;
      cin>>p>>y;
      city c={i,y,p,-1};
      cities[i]=c;
    }
    sort(cities,cities+m,compyear);
    int count[m]={};
    rep(i,m){
      count[cities[i].pref]++;
      cities[i].order=count[cities[i].pref];
    }
    sort(cities,cities+m,compid);
    rep(i,m){
      printf("%06d%06d\n",cities[i].pref,cities[i].order);
    }
    return 0;
}
