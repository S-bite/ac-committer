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
const long long INF = 1LL << 60;
using namespace std;
int n;
map<string, ll> mp;

void shiftX(vector<string> &s)
{
    rep(i, n)
    {
        s[i] = s[i].substr(1) + s[i][0];
        // cerr << s[i].size() << endl;
    }
}
void shiftY(vector<string> &s)
{
    string tmp = s[0];
    rep(j, n - 1)
    {
        string t = s[j + 1];
        s[j] = t; //.substr(0);
    }
    s.back() = tmp;
}

void add(vector<string> &s)
{
    string key = "";
    rep(i, n)
    {
        key += s[i];
    }
    //cerr << key << endl;
    mp[key]++;
}

int main(int argc, char const *argv[])
{
    cin >> n;
    vector<string> s(n, "");
    rep(i, n) cin >> s[i];
    rep(i, n)
    {
        rep(j, n)
        {
            add(s);
            shiftX(s);
        }
        shiftY(s);
        //add(s);
    }
    ll ans = 0;
    for (auto x : mp)
    {
        if (x.second != 1)
        {
            //cerr << x.second << endl;
            ans += x.second;
        }
    }
    cout << ans << endl;
    return 0;
}
