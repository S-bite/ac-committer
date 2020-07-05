#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
random_device rnd;
mt19937 mt(rnd());
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;

ll calc(priority_queue<ll, vector<ll>, greater<ll>> &qp, priority_queue<ll> &qm)
{
    ll ans = 1;
    while (!qp.empty())
    {
        ans *= qp.top();
        ans %= MOD;
        qp.pop();
    }
    while (!qm.empty())
    {
        cerr << qm.top() << endl;
        ans *= MOD + qm.top();
        ans %= MOD;
        qm.pop();
    }
    while (ans < 0)
        ans += MOD;
    return ans;
}

int main()
{
    int n, k;
    priority_queue<ll> pp;
    priority_queue<ll, vector<ll>, greater<ll>> pm;
    VL mmm;
    ll temp = 1;
    cin >> n >> k;
    rep(i, n)
    {
        ll t;
        cin >> t;
        if (t >= 0)
        {
            pp.push(t);
            temp *= t;
        }
        else
        {
            pm.push(t);
            mmm.push_back(t);
            temp *= MOD + t;
        }

        temp %= MOD;
    }
    if (n == k)
    {
        cout << temp << endl;
        return 0;
    }
    sort(ALL(mmm), greater<ll>());
    temp = 1;
    if (mmm.size() >= k)
    {
        rep(i, k)
        {
            temp *= MOD + mmm[i];
            temp %= MOD;
        }
    }
    priority_queue<ll, vector<ll>, greater<ll>> qp;
    priority_queue<ll> qm;
    rep(i, k)
    {
        if (pp.empty())
        {
            qm.push(pm.top());
            pm.pop();
        }
        else if (pm.empty())
        {
            qp.push(pp.top());
            pp.pop();
        }
        else if (llabs(pp.top()) > llabs(pm.top()))
        {
            qp.push(pp.top());
            pp.pop();
        }
        else
        {
            qm.push(pm.top());
            pm.pop();
        }
    }
    if (qm.size() % 2 == 0)
    {
        cout << calc(qp, qm) << endl;
        return 0;
    }
    else
    {
        bool canp = false;
        if (pp.size() == 0 && pp.size() == 0)
        {
        }
        else if (pp.size() == 0)
        {
            if (!qp.empty())
            {
                qp.pop();
                qm.push(pm.top());
                canp = true;
            }
        }
        else if (pm.size() == 0)
        {
            if (!qm.empty())
            {
                qm.pop();
                qp.push(pp.top());
                canp = true;
            }
        }
        else
        {
            if (qm.empty())
            {

                //a +出し-入れ
                ll ain = pm.top();
                ll aout = qp.top();
                qp.pop();
                qm.push(ain);
                canp = true;
            }
            else if (qp.empty())
            {
                //b -出し +入れ
                ll bin = pp.top();
                ll bout = qm.top();
                qm.pop();
                qp.push(bin);
                canp = true;
            }
            else
            {
                //a +出し-入れ
                ll ain = pm.top();
                ll aout = qp.top();
                //b -出し +入れ
                ll bin = pp.top();
                ll bout = qm.top();
                if (llabs(ain) * llabs(bout) < llabs(bin) * llabs(aout))
                {
                    qm.pop();
                    qp.push(bin);
                    canp = true;
                }
                else
                {
                    qp.pop();
                    qm.push(ain);
                    canp = true;
                }
            }
        }
        cerr << canp << endl;
        if (canp)
        {
            cout << calc(qp, qm) << endl;
        }
        else
        {
            if (mmm.size() >= k)
            {
                cout << temp << endl;
            }
            else
            {
                cout << calc(qp, qm) << endl;
            }
        }
    }

    return 0;
}
