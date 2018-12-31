#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int main()
{
  int h, w;
  cin >> h >> w;
  char c = 'A';
  rep(i, h)
  {
    rep(j, w)
    {
      string s;
      cin >> s;
      if (s == "snuke")
        cout << (char)('A' + j) << (i + 1) << endl;
    }
  }
  return 0;
}