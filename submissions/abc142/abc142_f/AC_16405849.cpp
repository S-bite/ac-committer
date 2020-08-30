#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const double EPS = 1e-3;
const double PI = 3.1415926535897932384626433832795028841971;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;
vector<int> visitlog;
bool hasloop = false;
int lastpos;

void dfs(vector<vector<int>> &g, int cur, vector<bool> &started,
         vector<bool> &finished) {
  started[cur] = true;
  visitlog.push_back(cur);

  for (auto &&next : g[cur]) {
    if (finished[next]) continue;
    if (started[next] && !finished[next]) {
      lastpos = next;
      hasloop = true;
      return;
    }
    dfs(g, next, started, finished);
    if (hasloop) return;
  }
  visitlog.pop_back();
  finished[cur] = true;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
  }
  rep(i, n) {
    vector<bool> started(n, false);
    vector<bool> finished(n, false);
    dfs(g, i, started, finished);
    if (hasloop) break;
    assert(visitlog.empty());
  }
  if (hasloop == false) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> loop;
  reverse(ALL(visitlog));

  rep(i, visitlog.size()) {
    loop.push_back(visitlog[i]);
    if (visitlog[i] == lastpos) {
      break;
    }
  }
  reverse(ALL(loop));

  while (true) {
    int startpos = -1, endpos = -1;
    vector<int> order(n, -1);
    rep(i, loop.size()) order[loop[i]] = i;
    rep(i, loop.size()) {
      for (auto &&next : g[loop[i]]) {
        if (order[next] != -1 && next != loop[(i + 1) % loop.size()]) {
          startpos = i;
          endpos = order[next];
        }
      }
    }

    if (startpos == -1) break;
    vector<int> nloop;
    nloop.push_back(loop[startpos]);
    while (startpos != endpos) {
      nloop.push_back(loop[endpos]);
      endpos = (endpos + 1) % loop.size();
    }
    loop = nloop;
  }
  cout << loop.size() << endl;
  for (auto &&x : loop) {
    cout << x + 1 << endl;
  }
  return 0;
}
