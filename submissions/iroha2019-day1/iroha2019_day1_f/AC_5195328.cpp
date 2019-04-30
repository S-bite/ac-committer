#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#ifdef DEBUG
#define line() cout << "[" << __LINE__ << "] ";
#define dump(i) cout << #i ": " << i << " ";
#define dumpl(i) cout << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;

void search(int n, int k, int prev, vector<int> &ret)
{
    if (n == 1)
    {
        ret = {-1};
        return;
    }
    if (k == 1)
    {
        ret.push_back(n);
        return;
    }
    while (n % prev != 0)
        prev++;
    n /= prev;
    ret.push_back(prev);
    search(n, k - 1, prev, ret);
    return;
}
int main(int argc, char const *argv[])
{

    int n, k;
    cin >> n >> k;
    vector<int> v;
    search(n, k, 2, v);
    rep(i, v.size()) cout << v[i] << " ";
    cout << endl;
    return 0;
}
