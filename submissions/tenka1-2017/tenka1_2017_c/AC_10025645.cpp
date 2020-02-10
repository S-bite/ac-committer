#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n;
  cin >> n;
  for (long long a = 1; a <= 3500; a++)
  {
    for (long long b = 1; b <= 3500; b++)
    {
      if (4 * a * b - n * a - n * b <= 0 || ((n * a * b) % (4 * a * b - n * a - n * b) != 0))
        continue;
      long long c = (n * a * b) / (4 * a * b - n * a - n * b);
      cout << a << " " << b << " " << c << endl;
      return 0;
    }
  }
  return 0;
}
