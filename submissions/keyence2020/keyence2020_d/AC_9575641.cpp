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

bool isvalidflip(ll flip)
{

    int one = 0;
    while (flip != 0)
    {
        one += (flip & 1);
        flip >>= 1;
    }
    return (one % 2 == 0);
}

int calc(int n, ll flip, vector<int> &a, vector<int> &b)
{
    vector<int> c(n);
    vector<int> d(n);
    vector<int> rev(n);
    rep(i, n)
    {
        rev[i] = (flip >> i) & 1;
        if (((flip >> i) & 1) == 0)
        {
            c[i] = a[i];
        }
        else
        {
            c[i] = b[i];
        }
        d[i] = c[i];
    }
    sort(ALL(c));
    vector<int> order(n);
    bool isok = false;
    map<int, bool> mp;
    mp.clear();
    rep(i, n)
    {
        isok = false;
        rep(j, n)
        {
            if (mp[j] == true)
            {
                continue;
            }
            if (d[i] == c[j] && ((rev[i] == 0 && abs(i - j) % 2 == 0) || (rev[i] == 1 && i != j && abs(i - j) % 2 == 1)))
            {
                //cerr << i << " " << j << endl;
                mp[j] = true;
                isok = true;
                order[i] = j;
                break;
            }
        }
        if (isok == false)
        {
            return -1;
        }
    }
    /*
    rep(i, n)
    {
        cerr << c[i] << " ";
    }
    cerr << endl;
    
    */
    int ret = 0;
    rep(i, n)
    {
        rep(j, i + 1, n)
        {
            if (order[i] > order[j])
            {
                ret++;
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    int n;
    int ans = (1 << 30);
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(flip, (1 << n))
    {
        // cerr << flip << endl;
        if (!isvalidflip(flip))
        {
            //  cerr << "invalid" << endl;
            continue;
        }
        int ret = calc(n, flip, a, b);
        //cerr << "valid: " << ret << endl;

        if (ret != -1)
        {
            ans = min(ans, ret);
        }
    }
    if (ans == (1 << 30))
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}
