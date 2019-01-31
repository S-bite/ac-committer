#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    string s;
    cin >> a >> b >> s;
    for (int i = 0; i < a + b + 1; i++)
    {

        if ((i == a && s[i] != '-') || (i != a && s[i] < '0') || (i != a && s[i] > '9'))
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}