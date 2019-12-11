#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    if (a.size() > b.size())
    {
        cout << "GREATER" << endl;
    }
    else if (a.size() < b.size())
    {
        cout << "LESS" << endl;
    }
    else
    {
        cout << ((a > b) ? "GREATER" : (a < b) ? "LESS" : "EQUAL") << endl;
    }
    return 0;
}