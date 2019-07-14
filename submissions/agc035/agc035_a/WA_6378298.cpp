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
	ll a[n];
	map<ll,int> mp;
	map<ll,bool> mp2;

	rep(i,n){
		cin>>a[i];
		mp[a[i]]++;
	}
	vector<ll> v;
	v.push_back(a[0]);
	mp[a[0]]--;
	rep(i,1,n){
		//cerr<<i<<" "<<mp[a[i]]<<endl;

		if (mp[a[i]]<=0){
			continue;
		}

		
		mp[a[i]]--;
		v.push_back(a[i]);
		
		//cerr<<i<<" "<<mp[a[i]]<<endl;

		ll b=(a[0]^a[i]);
		if (mp[b]<=0){
			break;
		}
		mp[b]--;
		//cerr<<i<<" "<<mp[a[i]]<<endl;

		v.insert(v.begin(),b);
	}
	if (v.size()!=n)
	{
		cout<<"No"<<endl;
		return 0;
	}
	//rep(i,n){
	//	cerr<<v[i]<<" "<<v[(i-1+n)%n]<<" "<<v[(i+1)%n]<<endl;
	//	if (v[i]!=(v[(i-1+n)%n]^v[(i+1)%n])){
	//		cout<<"No"<<endl;
//			return 0;
//		}
//	}
	cout<<"Yes"<<endl;
    return 0;
}
