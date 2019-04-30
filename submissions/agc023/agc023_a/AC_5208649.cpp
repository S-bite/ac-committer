#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long s[n];
    cin>>s[0];
    for(int i=0;i<n-1;i++){
        long long t;
        cin>>t;
        s[i+1]=s[i]+t;
    }
    sort(s,s+n);
  //for (int i=0;i<n;i++) cout<<s[i]<<" ";
 // cout<<endl;
    long long ans=0;
    long long tmp=1;
    long long prev=s[0];
    
    for (int i=1;i<n;i++){
       //out<<s[i]<<endl;
        if (s[i]==prev){
            tmp++;
        }else{
           //cout<<"add"<<tmp<<endl;
            prev=s[i];
            ans+=tmp*(tmp-1)/2;
            tmp=1;
           
        }
    }
    ans+=tmp*(tmp-1)/2;
    for (int i=0;i<n;i++){
        if (s[i]==0)ans++;}

    cout<<ans<<endl;
    return 0;
}