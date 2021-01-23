#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
using Mat = vector<vector<ll>>;

Mat dot(Mat a, Mat b)
{
    Mat c = Mat(3, VL(3, 0));
    rep(i, 3)
    {
        rep(j, 3)
        {
            rep(k, 3)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

Mat rotP()
{
    Mat c = {{0, 1, 0},
             {-1, 0, 0},
             {0, 0, 1}};
    return c;
}

Mat rotN()
{
    Mat c = {{0, -1, 0},
             {1, 0, 0},
             {0, 0, 1}};
    return c;
}

Mat invX(ll p)
{
    Mat x = {{1, 0, 0},
             {0, 1, -p},
             {0, 0, 1}};
    Mat y = {{1, 0, 0},
             {0, -1, 0},
             {0, 0, 1}};
    Mat z = {{1, 0, 0},
             {0, 1, p},
             {0, 0, 1}};
    z = dot(z, y);
    z = dot(z, x);
    return z;
}

Mat invY(ll p)
{
    Mat x = {{1, 0, -p},
             {0, 1, 0},
             {0, 0, 1}};
    Mat y = {{-1, 0, 0},
             {0, 1, 0},
             {0, 0, 1}};
    Mat z = {{1, 0, p},
             {0, 1, 0},
             {0, 0, 1}};
    z = dot(z, y);
    z = dot(z, x);
    return z;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> ps(n);
    rep(i, n)
    {
        cin >> ps[i].first >> ps[i].second;
    }
    int m;
    cin >> m;
    vector<Mat> mats(m + 1);
    mats[0] = {{1, 0, 0},
               {0, 1, 0},
               {0, 0, 1}};
    rep(i, m)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            mats[i + 1] = dot(rotP(), mats[i]);
        }
        else if (op == 2)
        {
            mats[i + 1] = dot(rotN(), mats[i]);
        }
        else if (op == 3)
        {
            ll p;
            cin >> p;
            mats[i + 1] = dot(invY(p), mats[i]);
        }
        else
        {
            ll p;
            cin >> p;
            mats[i + 1] = dot(invX(p), mats[i]);
        }
    }
    int q;
    cin >> q;
    rep(i, q)
    {
        int a, b;
        cin >> a >> b;
        b--;
        ll x = ps[b].first;
        ll y = ps[b].second;
        cout << x * mats[a][0][0] + y * mats[a][0][1] + mats[a][0][2] << " "
             << x * mats[a][1][0] + y * mats[a][1][1] + mats[a][1][2] << endl;
    }
    return 0;
}