#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll q,h,s,d,n;
    cin>>q>>h>>s>>d>>n;
    ll min1=min({4*q,2*h,s});
    ll min2=min({2*min1,d});
    cout<<min2*(n/2)+min1*(n%2)<<endl;
	return 0;
}
