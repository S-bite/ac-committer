#include <bits/stdc++.h>
#define fir first
#define sec second

using namespace std;
struct Union
{
  Union *par = this;
  int val = -1;
  int rank = 1;
};

Union *root(Union *t)
{
  if (t->par == t)
    return t;
  else
    return root(t->par);
}

void unite(Union *a, Union *b)
{
  if (a->rank > b->rank)
    root(b)->par = root(a);
  else
  {
    root(a)->par = root(b);
    if (a->rank == b->rank)
      b->rank++;
  }
}
bool same(Union *a, Union *b)
{
  return root(a) == root(b);
}

int main()
{
  int N, M, ans = 0;
  cin >> N >> M;
  pair<int, int> edge[M];
  for (int i = 0; i < M; i++)
  {
    cin >> edge[i].fir >> edge[i].sec;
    edge[i].fir--;
    edge[i].sec--;
  }
  for (int i = 0; i < M; i++)
  {
    Union u[N];
    for (int j = 0; j < M; j++)
    {
      if (j == i)
        continue;
      unite(&u[edge[j].fir], &u[edge[j].sec]);
    }
    bool isBridge = false;
    for (int j = 0; j < N; j++)
    {
      if (!same(&u[0], &u[j]))
      {
        isBridge = true;
        break;
      }
    }
    if (isBridge)
      ans++;
  }
  cout << ans << endl;
  return 0;
}
