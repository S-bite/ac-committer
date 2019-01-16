#include <bits/stdc++.h>
using namespace std;

int main()
{
    regex re[8];
    re[0] = "keyence.*";
    re[1] = "keyenc.*e";
    re[2] = "keyen.*ce";
    re[3] = "keye.*nce";
    re[4] = "key.*ence";
    re[5] = "ke.*yence";
    re[6] = "k.*eyence";
    re[7] = ".*keyence";
    string s;
    cin >> s;
    bool ret = false;
    for (int i = 0; i < s.size(); i++)
    {
        ret = ret || regex_match(s, re[i]);
    }
    cout << (ret ? "YES" : "NO") << endl;

    return 0;
}