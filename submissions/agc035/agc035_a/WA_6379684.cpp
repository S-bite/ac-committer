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
	int ind=random()%n;
	v.push_back(a[ind]);
	mp[a[ind]]--;
	rep(i,1,n){
		if (i==ind)
			continue;
		//cerr<<i<<" "<<mp[a[i]]<<endl;

		if (mp[a[i]]<=0){
			continue;
		}

		
		mp[a[i]]--;
		v.push_back(a[i]);
		
		//cerr<<i<<" "<<mp[a[i]]<<endl;

		ll b=(a[ind]^a[i]);
		if (mp[b]<=0){
			break;
		}
		mp[b]--;
		//cerr<<i<<" "<<mp[a[i]]<<endl;

		v.insert(v.begin(),b);
	}
	if (v.size()!=n)
	{
		return false;
	}

	return true;
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
	rep(i,10){
		if (is_ok(a,mp)){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
    return 0;
}
