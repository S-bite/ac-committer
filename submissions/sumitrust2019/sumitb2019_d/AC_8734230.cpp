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
using namespace std;

void inttovec(int n, vector<char> &v)
{
    v.clear();
    v.push_back('0' + (n / 100));
    n %= 100;
    v.push_back('0' + (n / 10));
    n %= 10;
    v.push_back('0' + n);
}

int main(int argc, char const *argv[])
{
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;

    rep(i, 1000)
    {
        vector<char> v;
        inttovec(i, v);
        int cur = 0;
        rep(j, n)
        {
            if (s[j] == v[cur])
            {
                cur++;
                if (cur == 3)
                {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
