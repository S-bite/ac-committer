#include <bits/stdc++.h>
using namespace std;

bool hasGemInPartialTree(map<int, vector<int>> &graph, vector<bool> &hasGem,
                         int cur, int par) {
  // cerr << "! " << cur << " " << par << endl;
  if (hasGem[cur]) {
    // cerr << "! " << cur << " has gem!" << endl;
    return true;
  }
  for (int next : graph[cur]) {
    if (next == par) continue;
    if (hasGemInPartialTree(graph, hasGem, next, cur)) return true;
  }
  return false;
}

int dfs(map<int, vector<int>> &graph, vector<bool> &hasGem, int cur, int par) {
  int cost = 0;
  // cerr << cur << " " << par << endl;
  for (int next : graph[cur]) {
    if (next == par) continue;
    if (hasGemInPartialTree(graph, hasGem, next, cur)) {
      // cerr << "enter " << next << endl;
      cost += dfs(graph, hasGem, next, cur) + 2;
      // cerr << "back from " << next << endl;
    }
  }
  return cost;
}

int main() {
  int n, x;
  cin >> n >> x;
  x--;
  map<int, vector<int>> graph;
  vector<bool> hasGem(n, false);
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    hasGem[i] = t == 1;
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  cout << dfs(graph, hasGem, x, -1) << endl;

  return 0;
}