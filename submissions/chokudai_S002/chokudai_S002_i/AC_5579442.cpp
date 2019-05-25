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

struct food
{
    int HP;
    int ATK;
    int id;
    bool operator<(const food &a) const
    {
        return (HP + a.ATK - 1) / a.ATK < (a.HP + ATK - 1) / ATK;
    };
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n], b[n];
    food foods[n];
    rep(i, n)
    {
        cin >> a[i] >> b[i];
        foods[i] = (food){a[i], b[i], i + 1};
    }
    sort(foods, foods + n);
    rep(i, n - 1)
    {
        if (!(foods[i] < foods[n - 1]))
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << foods[n - 1].id << endl;
    return 0;
}
