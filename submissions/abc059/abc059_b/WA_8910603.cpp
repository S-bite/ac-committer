#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    cout << ((a > b) ? "GREATER" : (a < b) ? "LESS" : "EQUAL" )<< endl;
    return 0;
}