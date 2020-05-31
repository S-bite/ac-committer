//from : https://atcoder.jp/contests/abc169/submissions/13867215
#define __mode_debug__
/*   ξ
     ll
   ＿ll＿
 ／  ∞  ＼
│*  Ａ  *│
│*  Ｃ  *│
│*  祈  *│
│*  願  *│
│*      *│
 ￣￣￣￣￣    */
//C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
#ifdef __mode_debug__
    #define DBG
#else
    #define DBG if(false)
#endif

#define LLINF (1LL<<60)
using ll = long long;
#define mod  1000000007

#define whole(a) (a).begin(),(a).end()
#define rwhole(a) (a).rbegin(),(a).rend()

#define repd(i,a,b) for (ll i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define rrepd(i,a,b) for(ll i=(a);i>=(b);i--)
#define each(itr,ds) for(auto itr=(ds).begin();itr!=(ds).end();itr++)

template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); }

//DUMP
//  ostream vector<T> , vector<vector<T>> , set<T> ,queue<T> , priority_queue<T> , pair<T,U> , map<T,U>
template<class T> ostream& operator<<(ostream&os,vector<T>&vec){os<<"{ ";rep(i,vec.size()) os<<((i==0)?"":", ")<<i<<":"<<vec[i];os<<" }";return os;}
template<class T> ostream& operator<<(ostream&os,vector<vector<T>>&vec){os<<"{"<<endl;rep(i,vec.size())os<<"\t   "<<i<<":"<<vec[i]<<((i==vec.size()-1)? "":",")<<endl;os<<"\t }";return os;}
template<class T> ostream& operator<<(ostream&os,set<T>&p){os<<"{ ";each(itr,p)  os<<((itr==p.begin())?"":", ")<<*itr;os<<" }";return os;}
template<class T> ostream& operator<<(ostream&os,queue<T>&p){queue<T> q(p);os<<"[< "<<(q.empty()?" <]":"");while(!q.empty()){os<<q.front();q.pop();os<< (q.empty() ? " <]" : ", ");}return os;}
template<class T> ostream& operator<<(ostream&os,priority_queue<T>&p){priority_queue<T> q(p);os<<"[< "<<(q.empty()?" <]":"");while(!q.empty()){os<<q.top();q.pop();os<< (q.empty() ? " <]" : ", ");}return os;}
template<class T,class U> ostream& operator<<(ostream&os,pair<T,U>&p){os<<"("<<p.first<<","<<p.second<<")";return os;}
template<class T,class U> ostream& operator<<(ostream&os,map<T,U>&p){os<<"{ ";each(itr,p)os<<((itr==p.begin())?"":", ")<<itr->first<<":"<<itr->second;os<<" }";return os;}
void dump_f(string &nm,char t){cerr<<endl;}
template<class T,class... Ts> void dump_f(string &nm,char t,T &&x,Ts&&... ts){int l=nm.find_first_of(',');string name(nm,0,l),nx(nm,l+1,-1);if(t=='\n') cerr<<"  "<<name<<"\t: "<<x<<t;else cerr << name<<": "<<x<<","<<t;dump_f(nx,t,forward<Ts>(ts)...);}
template<class... Ts> void dump_m(int &&ln,string &&nm,char t,Ts&&... ts){cerr<<"[ln: "<<ln<<"]"<<t;dump_f(nm,t,forward<Ts>(ts)...);}
#define dump(...) DBG dump_m(__LINE__,#__VA_ARGS__,'\n',__VA_ARGS__)
#define dl(...) DBG dump_m(__LINE__,#__VA_ARGS__,'\t',__VA_ARGS__)

#define lower_bound_idx(V,c) distance(V.begin(),lower_bound(whole(V),c))


bool issosu(ll n){
    bool is=true;
    if(n==1)return false;
    if(n==2)return true;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            is=false;
            break;
        }
    }
    return is;
}

int main() {
    ios::sync_with_stdio(false);//printf<=>cout
    cin.tie(nullptr);//cin<=>cout


    ll N;
    cin >>N;

    //-----------------------------------
    ll ans=0;
    for(ll i=2;i*i<=N;i++){
        ll u=0;
        while(N%i==0){
            N/=i;
            u++;
        }
        for(ll t=1;u>=0;t++){
            u-=t;
            if(u>=0)ans++;
        }
    }
    if(issosu(N))ans++;


    cout << ans <<'\n';


    return (0);
}
