#pragma GCC optimize("Ofast")
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
    //assert(half * 2 == n);

    complex<double> w = polar(1.0, -2.0 * PI / (double)n);
    double arg = -2.0 * PI / (double)n;
    for (int i = 0; i < half; i++)
    {
        even[i] = v[i] + v[half + i];
        auto tmp = (v[i] - v[half + i]); // * pow(w, i);
        double wr = cos(arg * i);
        double wi = sin(arg * i);

        odd[i].real(tmp.real() * wr - tmp.imag() * wi);
        odd[i].imag(tmp.real() * wi + tmp.imag() * wr);
    }
    fft(even);
    fft(odd);
    for (int i = 0; i < half; i++)
    {
        v[2 * i] = even[i];
        v[2 * i + 1] = odd[i];
    }
}

/*
void fft(vector<complex<double>> &v)
{

    int i = 0;
    int n = v.size();
    for (int j = 1; j < n - 1; j++)
    {
        for (int k = n >> 1; i > (i ^= k); k >>= 1)
        {
            if (j < i)
                swap(v[i], v[j]);
        }
    }
    for (int half = 1, m; (m = half << 1) <= n; half = m)
    {
        int irev = 0;
        for (int i = 0; i < n; i += m)
        {
            complex<double> w = polar(1.0, -2.0 * PI / (double)m);
            int k;
            for (k = n >> 2; k > (irev ^= k); k >>= 1)
            {
            }
            for (int j = i; j < half + i; j++)
            {

                k = j + half;
                auto x = v[j] - v[k];
                v[j] += v[k];
                v[k] = x * pow(w, irev);
            }
        }
    }
}*/

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
    int n = pow2_at_least(2 * (int)max(a.size(), b.size()) + 1);
    vector<complex<double>> x(n, (0, 0)), y(n, (0, 0));
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
        y[i] = x[i] * y[i];
    }
    ifft(y);
    rep(i, n)
    {
        c[i] = round(y[i].real());
    }
    return c;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    rep(i, n)
    {
        cin >> a[i + 1] >> b[i + 1];
    }
    auto ans = convolution(a, b);
    rep(i, 1, 2 * n + 1) cout << ans[i] << '\n';
    return 0;
}
