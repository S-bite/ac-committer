#include <bits/stdc++.h>
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
    b->par = root(a);
  else
  {
    a->par = root(b);
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
  int N, Q;
  cin >> N >> Q;
  Union u[N];
  for (int i = 0; i < Q; i++)
  {
    int c, a, b;
    cin >> c >> a >> b;
    if (c == 0)
      unite(&u[a], &u[b]);
    else
      cout << (same(&u[a], &u[b]) ? "Yes" : "No") << endl;
  }
  return 0;
}
