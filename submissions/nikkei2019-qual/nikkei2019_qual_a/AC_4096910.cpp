#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define MOD (1000000007ll)
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    cout << min(a, b) << " " << max(0, a + b - n) << endl;
    return 0;
}