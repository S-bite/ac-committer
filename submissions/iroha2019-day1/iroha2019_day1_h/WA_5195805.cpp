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

    string s;
    cin >> s;
    int m = 0;
    rep(i, s.size())
    {
        m += s[i] - '0';
    }
    int n = m;
    if (n % 9 != 0)
        cout << n % 9;
    n -= n % 9;
    while (n != 0)
    {
        cout << 9;
        n -= 9;
    }
    cout << endl;
    return 0;
}
