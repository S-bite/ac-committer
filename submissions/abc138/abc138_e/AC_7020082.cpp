#include <bits/stdc++.h>
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
map<char, bool> mp;
int main(int argc, char const *argv[])
{
    string s, t;
    cin >> s >> t;
    rep(i, s.size())
    {
        mp[s[i]] = true;
    }
    rep(i, t.size())
    {
        if (mp[t[i]] == false)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    map<char, vector<int>> pos;

    rep(i, s.size())
    {
        pos[s[i]].push_back(i);
    }
    int cnt = 0;
    int now = 0;
    int onelast = 0;
    while (now < t.size())
    {
        int i = 0; //*lower_bound(ALL(pos[t[now]]), 0);
        while (true)
        {
            if (t[now] == s[i])
            {

                now++;
                i++;
                if (now == t.size())
                {
                    onelast = i;
                    cnt++;
                    //cerr << "*" << 1 << endl;

                    break;
                }
            }
            else
            {
                //cerr << "n " << now << endl;
                auto itr = lower_bound(ALL(pos[t[now]]), i);
                if (itr == pos[t[now]].end())
                {
                    //  cerr << "*" << 2 << endl;
                    cnt++;
                    break;
                }
                //cerr << "c " << *itr << endl;
                i = *itr;
            }
        }
        //cnt++;
    }
    //cerr << cnt << endl;
    cout << s.size() * (cnt - 1) + onelast << endl;

    return 0;
}
