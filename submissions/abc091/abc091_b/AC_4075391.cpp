#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,int>mp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        mp[s]++;
    }
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        mp[s]--;
    }
   int ans=0;
   for (auto itr=mp.begin();itr!=mp.end();itr++){
    ans=max(ans,itr->second);
   }
    cout<<ans<<endl;
    return 0;
}


