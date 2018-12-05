#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int myrand()
{
    return rand() % 101;
}
int main()
{

    cout << 1000 << endl;
    rep(i, 1000)
    {
        cout << myrand() << " " << myrand() << " " << (myrand() + 1) << endl;
    }
    return 0;
}
