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
    vector<string> mark = {
        "N",
        "NNE",
        "NE",
        "ENE",
        "E",
        "ESE",
        "SE",
        "SSE",
        "S",
        "SSW",
        "SW",
        "WSW",
        "W",
        "WNW",
        "NW",
        "NNW",
    };
    vector<lld> power = {0.2,
                         1.5,
                         3.3,
                         5.4,
                         7.9,
                         10.7,
                         13.8,
                         17.1,
                         20.7,
                         24.4,
                         28.4,
                         32.6};
    int deg;
    lld p;
    cin >> deg >> p;
    string s = mark[0];
    int pp = 0;
    lld cur = 112.5;
    rep(i, 1, 16)
    {
        if (cur <= deg && deg < cur + 225)
        {
            s = mark[i];
        }
        cur += 225;
    }
    p = p / 60.0;

    cerr << fixed << setprecision(10) << p << endl;

    if ((int)(p * 100) - (int)(p * 10) * 10 >= 5)
    {
        p = (int)(p * 10);
        p++;
        p /= 10;
    }
    else if ((int)(p * 100) - (int)(p * 10) * 10 <= 4)
    {
        p = (int)(p * 10);
        p /= 10;
    }
    cerr << fixed << setprecision(10) << p << endl;

    for (int i = 11; i >= 0; i--)
    {
        if (p <= power[i] + 0.001)
            pp = i;
    }
    if (p >= 32.7)
        pp = 12;
    if (p <= 0.2)
        s = "C";
    cout << s << " " << pp << endl;

    return 0;
}
