//original:https://atcoder.jp/contests/dwango2015-prelims/submissions/16273513?lang=ja
#include <bits/stdc++.h>
using namespace std;
string s; 

void insertSpace(int x)
{
  for (size_t i = 0; i < x; i++)
  {
    cout << ' ' ;
  }
  return ;
}


void check(int i, int j)
{
  cout << "[STEP] i=" << i << ", j=" << j << ':' << endl;
  cout << "\t";
  insertSpace(i);
  cout << '.' ;
  insertSpace(j);
  cout << '\b';
  cout << '.' << endl;
  cout << "\t";
  cout << s << endl;
  cout << endl;
}



int main()
{
  cin >> s;
  long long ans = 0;
  for (size_t i = 0; i < s.length(); i++)
  {
    long long tmp = 0;
    if (s.at(i) == '2')
    {
      for (size_t j = 0; j < s.length(); j++)
      {
//        check(i,j);
        if (i + j + 1 < s.length() && s.at(i+j) == '2' && s.at(i+j+1) == '5')
        {
          tmp++;
          j++;
//          cout << "[UPDT] tmp = " << tmp << endl;
        }
        else
        {
          i += j ;
//          cout << "[END ] end\n" << endl;
          break;
        }
        if (i + j == s.length() - 1)
        {
          i += j + 2;
//          cout << "[END ] end\n" << endl;
          break;
        }
      }
    
    }
    ans += tmp * (tmp + 1) / 2;
  }
  cout << ans << endl;
}
