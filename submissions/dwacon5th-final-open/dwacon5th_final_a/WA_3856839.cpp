#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
using namespace std;
int main()
{
    ll n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    ll a[m], b[m];
    bool red[m], blue[m];
    map<ll, vector<ll>> mp;
    rep(i, m)
    {
        cin >> a[i] >> b[i];
        mp[a[i]].push_back(b[i]);
        mp[b[i]].push_back(a[i]);
    }
    rep(i, n)
    {
        red[i] = false;
        blue[i] = false;
    }

    rep(i, m)
    {
        if (s[b[i] - 1] == 'R')
            red[a[i]] = true;
        else
            blue[a[i]] = true;
        if (s[a[i] - 1] == 'R')
            red[b[i]] = true;
        else
            blue[b[i]] = true;
    }
    rep(i, n)
    {

        if (k % 2 == 0)
        {
            bool f = true;
            for (ll j : mp[i])
            {
                if (red[j])
                {
                    f = false;
                    break;
                }
            }
            if (f)
                cout << "First" << endl;
            else
                cout << "Second" << endl;
        }
        else
        {
            if (blue[i])
            {
                cout << "First" << endl;
            }
            else
                cout << "Second" << endl;
        }
    }

    return 0;
}