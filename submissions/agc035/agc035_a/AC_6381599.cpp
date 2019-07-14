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
int n;

bool is_ok(vector<ll> &a,map<ll,int> mp){


	vector<ll> v;
	
	v.push_back(a[0]);
	mp[a[0]]--;
	int start=-1;
	rep(i,1,n){
		mp[a[i]]--;
		if (mp[a[i]^a[0]]>0){
		v.push_back(a[i]);
			start=i;
			break;
		}
		mp[a[i]]++;
	}
	if (start==-1){
		return false;
	}
	n-=2;
	while (n){
		int x=v[v.size()-1],y=v[v.size()-2];
		if (mp[x^y]<=0){
			return false;
		}
		v.push_back(x^y);
		mp[x^y]--;
		n--;
	}
	return (v[0]==(v[1]^v[v.size()-1]) && (v[v.size()-1]==(v[v.size()-2]^v[0]) ));
}

int main(int argc, char const *argv[])
{
	cin>>n;
	vector<ll> a(n,0);
	map<ll,int> mp;
	rep(i,n){
		cin>>a[i];
		mp[a[i]]++;
	}
	if (is_ok(a,mp)){
		cout<<"Yes"<<endl;
		return 0;
	}
	cout<<"No"<<endl;
    return 0;
}
