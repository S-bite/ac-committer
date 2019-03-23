#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] " << endl;
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;
vector<int> bfs(vector<int> v, vector<int> now, int last)
{

    if (v.empty())
    {
        return now;
    }
    int i = v.size();
    for (auto itr = v.end() - 1; itr != v.begin() - 1; itr--)
    {
        auto _v = v;
        if (i == *itr)
        {
            _v.erase(_v.begin() + i - 1);
            now.push_back(i);

            vector<int> res = bfs(_v, now, i - 1);
            if (res[0] != -1)
                return res;
            now.pop_back();
        }
        i--;
    }

    vector<int> ret = {-1};
    return ret;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> b;
    rep(i, n)
    {
        int t;
        cin >> t;
        b.push_back(t);
    }
    auto res = bfs(b, {}, 0);
    reverse(res.begin(), res.end());
    for (int ans : res)
    {
        cout << ans << endl;
    }
    return 0;
}
