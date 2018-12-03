#include <bits/stdc++.h>

using namespace std;

int main() {
    string a,b;
    cin>>a>>b;
    int n=atoi((a+b).c_str());
    cout<<n<<endl;
    if(floor(sqrt(n))==sqrt(n))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
	return 0;
}
