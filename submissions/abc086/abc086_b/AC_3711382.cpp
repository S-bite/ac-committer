#include <bits/stdc++.h>

using namespace std;

bool is_pow2(int n){
    for(int i=0;i<=sqrt(n)+1;i++){
        if (i*i==n) return true;
    }   
    return false;
}

int main() {
    string a,b;
    cin>>a>>b;
    int n=atoi((a+b).c_str());
    if(is_pow2(n))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
	return 0;
}
