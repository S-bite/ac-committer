#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define fir first
#define sec second
using namespace std;

int main()
{
    int n;
    cin >> n;

    pair<int, int> p[n];
    rep(i, n) cin >> p[i].fir >> p[i].sec;
    rep(i, n) cout << i << endl;
    return 0;
}