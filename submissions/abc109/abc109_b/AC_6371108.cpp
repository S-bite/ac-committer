#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
#define MOD 1000000007ll

using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	map<string,bool> mp;
	string last="@";
	rep(i,n){
		string s;
		cin>>s;
		if (mp[s]==true || (last!="@" && last[last.size()-1]!=s[0])){
			cout<<"No"<<endl;
			return 0;
		}
		mp[s]=true;
		last=s;
	}
	cout<<"Yes"<<endl;
    return 0;
}
