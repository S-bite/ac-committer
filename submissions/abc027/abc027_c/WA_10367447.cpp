#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    vector<int> v;
    while (n > 0)
    {
        v.push_back(n % 2);
        n /= 2;
    }
    reverse(ALL(v));
    rep(i, v.size()) cerr << v[i] << " ";
    cerr << endl;
    bool twin;
    if (v.size() % 2 == 0)
    {
        twin = true;
        rep(i, 1, v.size())
        {
            if (i % 2 == 0 && v[i] == 0)
            {
                twin = true;
                break;
            }
            if (i % 2 == 1 && v[i] == 1)
            {
                twin = false;
                break;
            }
        }
    }
    else
    {
        //cerr << "odd" << endl;
        twin = false;
        rep(i, 1, v.size())
        {
            if (i % 2 == 1 && v[i] == 0)
            {
                twin = true;
                break;
            }
            if (i % 2 == 0 && v[i] == 1)
            {
                twin = false;
                break;
            }
        }
    }
    cout << (twin ? "Takahashi" : "Aoki") << endl;

    return 0;
}
