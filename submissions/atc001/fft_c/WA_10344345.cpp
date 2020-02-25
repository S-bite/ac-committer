#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

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
    complex<double> w = exp((complex<double>)(-2 * M_PI * 1.0i) / (double)n);
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

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int size = 1;
    while (size < n)
        size *= 2;
    size *= 2;
    vector<complex<double>> a(size, (0, 0)), b(size, (0, 0)), c(size);
    rep(i, n)
    {
        double x, y;
        cin >> x >> y;
        a[i].real(x);
        b[i + 1].real(y);
    }
    fft(a);
    fft(b);
    rep(i, size)
    {
        c[i] = a[i] * b[i];
        c[i] = conj(c[i]);
    }
    fft(c);
    rep(i, size)
    {
        c[i] = conj(c[i]) / (double)size;
    }
    rep(i, 2 * n)
    {
        int num = c[i].real();
        cout << num << endl;
    }
    return 0;
}
