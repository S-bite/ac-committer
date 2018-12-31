#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int main()
{
  int n;
  cin >> n;
  int t = 0;
  rep(i, n)
  {
    if ((t + 1) * t / 2 > n)
      break;
    t++;
  }
  while (n != 0)
  {
    if (t <= n)
    {
      cout << t << endl;
      n -= t;
    }
    t--;
  }
  return 0;
}