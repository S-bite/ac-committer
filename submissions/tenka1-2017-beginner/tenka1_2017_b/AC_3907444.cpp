#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int main()
{
  int n;
  cin >> n;
  int m = -1, p = 0;
  rep(i, n)
  {
    int a, b;
    cin >> a >> b;
    if (a > m)
    {
      m = a;
      p = b;
    }
  }
  cout << (m + p) << endl;
  return 0;
}