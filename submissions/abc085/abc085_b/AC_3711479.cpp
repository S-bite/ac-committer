#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int d[n];
    for(int i=0;i<n;i++) cin>>d[i];
    sort(d,d+n);
    int ans=0,nowd=-1;
    for(int i=0;i<n;i++){
        if(d[i]>nowd){
            ans++;
            nowd=d[i];
        }
    }
    cout<<ans<<endl;
	return 0;
}
