#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
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
#define EPS (1e-10)
using namespace std;

double add(double a, double b)
{

    if (abs(a + b) < EPS * (abs(a) + abs(b)))
        return 0;
    return a + b;
}

struct P
{
    double x, y;
    P(){};
    P(double x, double y) : x(x), y(y) {}
    P operator+(P p)
    {
        return (P(add(x, p.x), add(y, p.y)));
    }
    P operator-(P p)
    {
        return (P(add(x, -p.x), add(y, -p.y)));
    }
    P operator*(double k)
    {
        return (P(k * x, k * y));
    }
    double dot(P p)
    {
        return add(x * p.x, y * p.y);
    }
    double det(P p)
    {
        return add(x * p.y, -y * p.x);
    }

    bool on_seg(P p1, P p2, P q)
    {
        return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
    }
    P intersection(P p1, P p2, P q1, P q2)
    {
        return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
    }
};

typedef P Vector;
//三辺の長さがそれぞれa,b,cの三角形の面積を求める
double heron(double a, double b, double c)
{
    double s = (a + b + c) / 2;

    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// p1-p2の線分の長さを求める
double distPP(P p1, P p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// 線分p1-p2と点qの長さを求める
double distLP(P p1, P p2, P q)
{
    return (p2 - p1).det(q - p1) / distPP(p2, p1);
}

int main(int argc, char const *argv[])
{
    P p;
    cin >> p.x >> p.y;
    int n;
    cin >> n;
    P b[n];
    rep(i, n)
    {
        cin >> b[i].x >> b[i].y;
    }
    double ans = 101010.0;
    rep(i, n)
    {
        ans = min(ans, distLP(b[i], b[(i + 1) % n], p));
        cerr << b[i].x << " " << b[i].y << endl;
    }
    cout << std::setprecision(10) << ans << endl;

    return 0;
}
