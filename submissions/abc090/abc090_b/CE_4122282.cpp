#include<bits>#include <bits/stdc++.h>
using namespace std;
bool is_palindromic(int n)
{
    int p[5];
    for (int i = 0; i < 5; i++)
    {
        p[i] = n % 10;
        n /= 10;
    }
    return (p[0] == p[4] && p[1] == p[3]);
}
int main()
{
    int a, b, ans = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (is_palindromic(i))
            ans++;
    }
    cout << ans << endl;
    return 0;
}