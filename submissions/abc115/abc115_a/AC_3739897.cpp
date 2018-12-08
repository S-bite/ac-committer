#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ll long long
using namespace std;
int main()
{
    int d;
    cin >> d;
    cout << "Christmas ";

    rep(i, 25 - d) cout << "Eve" << ((i == 25 - d - 1) ? "" : " ");
    cout << endl;
    return 0;
}