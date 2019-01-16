#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n;
    cin >> s >> n;
    n--;
    cout << s[n / 5] << s[n % 5] << endl;

    return 0;
}