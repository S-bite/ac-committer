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
int ans;

vector<int> z_algorithm(const string &s)
{
  vector<int> prefix(s.size());
  for (int i = 1, j = 0; i < s.size(); i++)
  {
    if (i + prefix[i - j] < j + prefix[j])
    {
      prefix[i] = prefix[i - j];
    }
    else
    {
      int k = max(0, j + prefix[j] - i);
      while (i + k < s.size() && s[k] == s[i + k])
        ++k;
      prefix[i] = k;
      j = i;
    }
  }
  prefix[0] = (int)s.size();
  return prefix;
}
int main(int argc, char const *argv[])
{
  string s;
  int n;
  cin >> n >> s;
  ans = 0;
  rep(i, n)
  {
    string t = s.substr(i);
    //cerr << t << endl;
    auto ret = z_algorithm(t);
    rep(j, ret.size())
    {
      //cerr << ret[j] << " ";
      if (j >= ret[j])
      {
        ans = max(ans, ret[j]);
      }
    }
    //cerr << endl;
  }
  cout << ans << endl;
  return 0;
}
