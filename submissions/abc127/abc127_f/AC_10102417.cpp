#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

int main(int argc, char const *argv[])
{
    int q;
    cin >> q;
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    ll c = 0;
    int med = 0;
    ll sum1 = 0;
    ll sum2 = 0;
    rep(i, q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int a, b;
            cin >> a >> b;
            c += b;
            if (pq1.size() > pq2.size())
            {
                if (a < med)
                {
                    pq2.push(pq1.top());
                    sum2 += pq1.top();
                    sum1 -= pq1.top();
                    pq1.pop();
                    pq1.push(a);
                    sum1 += a;
                }
                else
                {
                    pq2.push(a);
                    sum2 += a;
                }
                med = pq1.top();
            }
            else if (pq1.size() == pq2.size())
            {
                if (a < med)
                {
                    pq1.push(a);
                    sum1 += a;
                    med = pq1.top();
                }
                else
                {
                    pq2.push(a);
                    sum2 += a;
                    med = pq2.top();
                }
            }
            else
            {
                if (a > med)
                {
                    pq1.push(pq2.top());
                    sum1 += pq2.top();
                    sum2 -= pq2.top();
                    pq2.pop();
                    pq2.push(a);
                    sum2 += a;
                }
                else
                {
                    pq1.push(a);
                    sum1 += a;
                }
                med = pq1.top();
            }
        }
        else
        {
            ll value = c + (med * pq1.size() - sum1) + (sum2 - med * pq2.size());
            cout << med << " " << value << endl;
        }
    }
    return 0;
}
