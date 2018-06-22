#include <bits/stdc++.h>
using namespace std;
int main(){ 
        int K,S;
        int ans=0;
        cin>>K>>S;
        for (int x=0;x<=K;x++){
                for (int y=0;y<=K;y++){
                        if ((S-x-y)<=K and (S-x-y)>=0){
                                ans++;
                        }
                }
        }
        cout<<ans<<endl;
}
