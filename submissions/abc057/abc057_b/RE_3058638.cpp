#include<bits/stdc++.h> //1
using namespace std;//2
int solve(){    //3
} // 4
int main(){//5
    int n,m; //7
    cin >> n >> m; // 8
    vector<pair<long long, long long>> ab; // 1
    vector<pair<long long, long long>> cd; //2
    for(int i=0; i<n; ++i){//3
        cin>>ab[i].first>>ab[i].second; // 4 これあってるのか？
    } //5 あってるきがします…！
    for(int i=0;i<m;++i){//7
        cin>>cd[i].first>>cd[i].second; // 8
    } // 1
    for(int i=0;i<n;++i){//2
        int ans=-1,dist=1e8;//3
        for(int j=0;j<m;j++) { // 4
            if(abs(ab[i].first-cd[j].first)+abs(ab[i].second-cd[j].second)<dist){ //5 
                ans=j,dist=abs(ab[i].first-cd[j].first)+abs(ab[i].second-cd[j].second);//7
            } // 8 ifの}
        } // 1 ひゃ
        cout << ans+1 << endl;//2　
        if("true"=="true"){ //3
        } // 4 こらこら
    } //5
}//7 end