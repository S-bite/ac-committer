#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;

const ll INF = 1ll << 60;
ll n, k;

bool canbuild(vector<ll> &v, ll num)
{
    vector<int> m(n);
    ll tsum = 0;
    rep(i, n)
    {
        m[i] = v[i] % num;
        tsum += m[i];
    }
    sort(ALL(m), greater<ll>());
    int tail = n - 1;

    assert(tsum % num == 0);
    ll diff = 0;
    ll cost = 0;
    rep(i, n)
    {
        if (m[i] == 0)
            break;
        int diff = 0;
        diff = num - m[i];
        cost += diff;
        while (diff != 0)
        {
            if (diff <= m[tail])
            {
                m[tail] -= diff;
                diff = 0;
            }
            else
            {
                diff -= m[tail];
                m[tail] = 0;
                tail--;
            }
        }
    }

    /*
    rep(i, n)
    {
        //cerr << cost << endl;
        if (diff < 0)
        {
            if (m[i] + diff >= 0)
            {
                m[i] += diff;
                diff = 0;
            }
            else
            {
                diff += m[i];
                m[i] = 0;
            }
        }
        else
        {
            if (m[i] + diff <= num)
            {
                m[i] += diff;
                m[i] %= num;
                diff = 0;
            }
            else
            {
                diff -= num - m[i];
                m[i] = 0;
            }
        }
        if (num - m[i] < m[i]) //足したほうが少ない
        {
            cost += num - m[i];
            diff -= num - m[i];
        }
        else
        {
            cost += m[i];
            diff = m[i];
        }
    }*/
    //cerr << num << " " << cost << endl;
    return cost <= k;
}

int main()
{
    cin >> n >> k;
    vector<ll> v(n);
    ll sum = 0;
    rep(i, n)
    {
        cin >> v[i];
        sum += v[i];
    }
    sort(ALL(v));
    vector<ll> candid;
    ll cur = 1;
    for (ll cur = sum; cur >= 1; cur--)
    {
        if (sum % cur == 0)
        {
            if (canbuild(v, cur))
            {
                cout << cur << endl;
                return 0;
            }
        }
    }
    return 0;
}