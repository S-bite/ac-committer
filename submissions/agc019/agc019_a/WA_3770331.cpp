#include <bits/stdc++.h>
using namespace std;
int main() {
    int q,h,s,d,n;
    cin>>q>>h>>s>>d>>n;
    int min1=min({4*q,2*h,s});
    int min2=min({2*min1,d});
    cout<<min2*(n/2)+min1*(n%2)<<endl;
	return 0;
}
