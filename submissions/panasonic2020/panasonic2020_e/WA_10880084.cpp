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

vector<string> ans;
map<string, bool> mp;
int n;
string concat(string a, string b)
{
    rep(i, a.size())
    {
        bool flag = true;
        //cerr << i << endl;
        rep(j, i, a.size())
        {
            if (j - i == b.size())
                break;
            if (a[j] == '?')
            {
                //a[i + j] = b[j];
                continue;
            }
            if (b[j - i] == '?')
            {
                //b[j] = a[i + j];
                continue;
            }
            if (a[j] != b[j - i])
            {
                //cerr << "!" << j << " " << j - i << endl;
                flag = false;
                break;
            }
        }
        if (flag)
        {
            string ret = "";
            rep(k, i)
            {
                ret += a[k];
            }
            int alen = a.size() - i;
            int blen = b.size();
            // cerr << i << " " << alen << " " << blen << endl;

            if (alen > blen)
            {
                rep(k, alen)
                {
                    if (i + k < blen && a[i + k] == '?')
                    {
                        ret += b[i + k];
                    }
                    else
                    {
                        ret += a[k];
                    }
                }
            }
            else
            {
                rep(k, blen)
                {
                    if (i + k < alen && b[i + k] == '?')
                    {
                        ret += a[i + k];
                    }
                    else
                    {
                        ret += b[k];
                    }
                }
            }
            return ret;
        }
    }
    return a + b;
}

int main()
{
    vector<string> v(3);
    cin >> v[0] >> v[1] >> v[2];
    vector<int> order = {0, 1, 2};
    int ans = IINF;
    do
    {
        string s = concat(v[order[0]], v[order[1]]);
        s = concat(s, v[order[2]]);
        ans = min(ans, (int)s.size());
        s = concat(v[order[0]], v[order[1]]);
        s = concat(v[order[2]], s);
        ans = min(ans, (int)s.size());
    } while (next_permutation(ALL(order)));
    cout << ans << endl;
    return 0;
}