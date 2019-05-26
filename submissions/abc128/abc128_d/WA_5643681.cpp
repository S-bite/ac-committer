#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <bitset>
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

    int N, K;
    cin >> N >> K;
    vector<ll> v(N, 0);
    rep(i, N) cin >> v[i];
    ll ans = 0;

    rep(k, 1, K + 1)
    {
        ll right = k, left = 0;

        for (; left != k + 1; right--, left++)
        {
            // cerr << left << "," << right << endl;
            ll tmpsum = 0;
            vector<ll> tmpvec;
            rep(i, left)
            {
                tmpsum += v[i];
                tmpvec.push_back(v[i]);
            }
            rep(i, right)
            {
                tmpsum += v[N - 1 - i];
                tmpvec.push_back(v[N - 1 - i]);
            }
            sort(ALL(tmpvec));
            rep(i, K - k)
            {
                tmpsum -= tmpvec[i];
            }
            ans = max(ans, tmpsum);
        }
    }
    cout << ans << endl;
    return 0;
}
