#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
int main(){
    int n,t,a;
    cin>>n>>t>>a;
    int ans=-1;
    double best=99999.0;
    rep(i,n) {
        int h;
        cin>>h;
        if (best>abs((double)a-((double)t-0.006*h))){
            best=abs((double)a-((double)t-0.006*h));
            ans=i;
        }
    }
    cout<<(ans+1)<<endl;
    return 0;
}