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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<int, char>> v(1);
    v[0] = {1, s[0]};
    rep(i, 1, n)
    {
        if (s[i] == v.back().second)
        {
            v.back().first++;
        }
        else
        {
            v.push_back({1, s[i]});
        }
    }
    int ans = 0;
    rep(i, n)
    {

        int cnt = 0, j = 0, now = 0;
        while (true)
        {
            //            cerr << i << "," << j << "," << cnt << "," << ans << "," << now << endl;
            if (i + j == v.size() + 1)
            {
                cout << max(ans, now) << endl;
                return 0;
            }
            now += v[i + j].first;
            if (v[i + j].second == '0')
                cnt++;
            if (cnt == k + 1)
            {
                now -= v[i + j].first;
                break;
            }
            j++;
        }
        ans = max(ans, now);
    }
    return 0;
}
