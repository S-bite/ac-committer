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
    int ans = 0, now = 0, zero = 0;
    queue<pair<int, char>> que;
    rep(i, v.size())
    {
        pair<int, char> p = v[i];
        now += p.first;
        que.push(p);
        if (p.second == '0')
        {
            zero++;
        }
        if (zero > k)
        {
            while (que.front().second != '0')
            {
                now -= que.front().first;
                que.pop();
            }
            now -= que.front().first;
            que.pop();

            zero--;
        }
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}
