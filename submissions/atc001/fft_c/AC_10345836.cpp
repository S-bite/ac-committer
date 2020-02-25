#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const double EPS = 1e-3;
const double PI = 3.1415926535897932384626433832795028841971;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

void fft(vector<complex<double>> &v)
{
    int n = (int)v.size();
    if (n <= 1)
        return;
    int half = n / 2;
    vector<complex<double>> even(half), odd(half);
    assert(half * 2 == n);
    complex<double> w = polar(1.0, -2.0 * PI / (double)n);
    for (int i = 0; i < half; i++)
    {
        even[i] = v[i] + v[half + i];
        odd[i] = (v[i] - v[half + i]) * pow(w, i);
    }
    fft(even);
    fft(odd);
    for (int i = 0; i < half; i++)
    {
        v[2 * i] = even[i];
        v[2 * i + 1] = odd[i];
    }
}

void ifft(vector<complex<double>> &v)
{
    int n = (int)v.size();
    for (auto &x : v)
        x = conj(x);
    fft(v);
    for (auto &x : v)
        x = conj(x) / (double)n;
}

int pow2_at_least(int n)
{
    int ret = 1;
    while (ret < n)
        ret *= 2;
    return ret;
}

vector<int> convolution(vector<int> &a, vector<int> &b)
{
    int n = pow2_at_least((int)2 * max(a.size(), b.size()) + 1);
    vector<complex<double>> x(n, (0, 0)), y(n, (0, 0)), z(n, (0, 0));
    vector<int> c(n, 0);
    rep(i, a.size())
    {
        x[i].real(a[i]);
    }
    rep(i, b.size())
    {
        y[i].real(b[i]);
    }
    fft(x);
    fft(y);
    rep(i, n)
    {
        z[i] = x[i] * y[i];
        z[i] = conj(z[i]);
    }
    fft(z);
    rep(i, n)
    {
        z[i] /= n;
        c[i] = round(z[i].real());
    }
    return c;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    rep(i, n)
    {
        cin >> a[i + 1] >> b[i + 1];
    }
    auto ans = convolution(a, b);
    rep(i, 1, 2 * n + 1) cout << ans[i] << endl;
    return 0;
}
