#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  for (int a = 1; a <= 3500; a++)
  {
    for (int b = 1; b <= 3500; b++)
    {
      if (4 * a * b - n * a - n * b <= 0 || ((n * a * b) % (4 * a * b - n * a - n * b) != 0))
        continue;
      int c = (n * a * b) / (4 * a * b - n * a - n * b);
      cout << a << " " << b << " " << c << endl;
      return 0;
    }
  }
  return 0;
}
