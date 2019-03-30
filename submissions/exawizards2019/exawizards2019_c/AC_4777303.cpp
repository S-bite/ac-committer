#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
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
int simulate(int target, vector<char> t, vector<char> d, string s)
{
    cerr << target;
    int q = t.size();
    rep(i, q)
    {
        if (target == -1 || target == s.size())
            break;

        if (t[i] == s[target])
        {
            if (d[i] == 'L')
                target--;
            else
                target++;
        }
    }
    cerr << "->" << target << endl;

    return target;
}

int main(int argc, char const *argv[])
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<char> t, d;
    rep(i, q)
    {
        char _t, _d;
        cin >> _t >> _d;
        t.push_back(_t);
        d.push_back(_d);
    }
    int right = n, left = -1;
    while (left + 1 != right)
    {
        int med = (right + left) / 2;
        if (simulate(med, t, d, s) != -1)
        {
            right = med;
        }
        else
        {
            left = med;
        }
        cerr << left << "," << right << endl;
    }
    int start = right;

    right = n;
    left = -1;
    while (left + 1 != right)
    {
        int med = (right + left) / 2;
        if (simulate(med, t, d, s) != n)
        {
            left = med;
        }
        else
        {
            right = med;
        }
        cerr << left << "," << right << endl;
    }
    int end = left;
    cerr << start << endl;
    cerr << end << endl;

    cout << end - start + 1 << endl;
    return 0;
}
