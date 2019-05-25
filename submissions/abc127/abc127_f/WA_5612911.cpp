#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
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
int main(int argc, char const *argv[])
{
    int Q;
    ll size = 0;
    ll c = 0;
    cin >> Q;
    vector<ll> v;
    ll l = 0, r = 0, rs = 0, ls = 0;
    int last = 0;
    rep(i, Q)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            ll a, b;
            cin >> a >> b;
            //cerr << a << " " << b << endl;
            auto itr = lower_bound(ALL(v), a);
            int now = itr - v.begin();
            v.insert(itr, a);
            size++;
            c += b;
            if (v[size / 2] > a)
            {
                l += a;
                ls++;
            }
            else
            {
                r += a;
                rs++;
            }
        }
        else
        {

            ll med = v[(size - 1) / 2];

            auto itr = lower_bound(ALL(v), med);
            int now = itr - v.begin();

            //  cerr << c << ", " << l << ", " << r << ", " << now << endl;
            cout << med << " " << ((r - (rs)*med) + (ls * med - l) + c) << endl;
        }
    }
    return 0;
}
