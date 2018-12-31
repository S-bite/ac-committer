#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int main()
{
  int col[9];
  rep(i, 9) col[i] = 0;

  int n;
  cin >> n;
  rep(i, n)
  {
    int t;
    cin >> t;
    if (t >= 3200)
      col[8]++;
    else
      col[t / 400]++;
  }
  int ans = 0, ansmax, ansmin;
  rep(i, 8) if (col[i] > 0) ans++;
  ansmax = ans;
  ansmin = ans;
  if (col[8] > 0 and ans == 0)
    ansmin++;
  ansmax = ans + col[8];
  cout << ansmin << " " << ansmax << endl;
  return 0;
}