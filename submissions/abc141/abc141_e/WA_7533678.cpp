#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;

bool haschar(string s, char c, int n)
{
  rep(i, n + 1)
  {
    if (s[i] == c)
    {
      return true;
    }
  }
  return false;
}

int lcs(string s, string t)
{
  int dp[s.size()][t.size()];
  bool f = false;
  rep(i, s.size())
  {
    if (f == true)
    {
      dp[i][0] = 1;
    }
    else if (haschar(t, s[i], i))
    {
      f = true;
      dp[i][0] = 1;
    }
    else
    {
      dp[i][0] = 0;
    }
  }
  f = false;
  rep(i, t.size())
  {
    if (f == true)
    {
      dp[0][i] = 1;
    }
    else if (haschar(s, t[i], i))
    {
      f = true;
      dp[0][i] = 1;
    }
    else
    {
      dp[0][i] = 0;
    }
  }

  rep(i, 1, s.size()) rep(j, 1, t.size())
  {
    if (s[i] == t[j])
    {
      dp[i][j] = dp[i - 1][j - 1] + 1;
    }
    else
    {
      dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    }
  }
  return dp[s.size() - 1][t.size() - 1];
}

int main(int argc, char const *argv[])
{
  string s;
  int n;
  cin >> n >> s;
  int ans = 0;
  rep(i, 1, s.size() - 1)
  {
    string a = s.substr(0, i);
    string b = s.substr(i);
    ans = max(ans, lcs(a, b));
  }

  cout << ans << endl;
  return 0;
}
