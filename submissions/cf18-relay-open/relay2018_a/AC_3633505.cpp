#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
string week[] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int get_index(string s){
      rep(i,7) if (week[i]==s) return i;
};

int main() {
    int n;
    cin>>n;
    rep(i,n){
        string s;
        cin>>s;
        cout<<week[(get_index(s)+1)%7]<<endl;
    }

	return 0;
}
