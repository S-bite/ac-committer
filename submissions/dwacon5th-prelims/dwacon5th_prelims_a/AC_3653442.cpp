#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    double sum=0;
    rep(i,n){
     cin>>a[i];
     sum+=a[i];
    }
    sum/=(double)n;
    long double diff=100000.0;
    int ans=0;
    rep(i,n) {
        if(abs((double)a[i]-sum)<diff){
            diff=fabs((double)a[i]-sum);
           // cout<<diff<<endl;
            ans=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}