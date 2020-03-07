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
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<int> qtype(q);
    vector<bool> isrev(q + 1, false);
    int revnum = 0;

    map<int, char> addchar;
    map<int, bool> addfront;
    rep(i, q)
    {
        int t;
        cin >> t;
        qtype[i] = t;
        if (t == 1)
        {
            revnum++;
        }
        if (t == 2)
        {
            int f;
            char c;
            cin >> f >> c;
            addchar[i] = c;
            addfront[i] = (f == 1);
        }
    }

    int cur = 0;
    rep(i, q)
    {
        if (qtype[i] == 1)
            cur++;

        isrev[i] = (revnum - cur) % 2;
    }
    if (isrev[0])
    {
        reverse(ALL(s));
    }
    deque<char> que;
    rep(i, s.size())
    {
        que.push_back(s[i]);
    }
    rep(i, q)
    {
        if (qtype[i] == 2)
        {
            if (addfront[i] ^ isrev[i])
            {
                que.push_front(addchar[i]);
            }
            else
            {
                que.push_back(addchar[i]);
            }
        }
    }
    while (!que.empty())
    {
        cout << que.front();
        que.pop_front();
    }
    cout << endl;
    return 0;
}
