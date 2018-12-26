#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int main()
{
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  map<int, bool> mp;
  mp[a] = true;
  mp[b] = true;
  rep(i, k)
  {
    int t;
    cin >> t;
    if (mp[t] == true)
    {
      cout << "NO" << endl;
      return 0;
    }
    else
    {
      mp[t] = true;
    }
  }
  cout << "YES" << endl;
  return 0;
}