#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
random_device rnd;
mt19937 mt(rnd());

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

typedef string::const_iterator State;
class ParseError
{
};
string set_or_dict(State &begin);
string number(State &begin)
{
    while (isdigit(*begin))
        begin++;
    return "number";
}
string expr(State &begin)
{
    if (isdigit(*begin))
        return number(begin);
    else
        return set_or_dict(begin);
}

string set_or_dict(State &begin)
{
    begin++;
    expr(begin);
    string ret = "";
    if (*begin == ':')
    {
        ret = "dict";
        begin++;
        expr(begin);
        while (*begin != '}')
        {
            begin++;
            expr(begin);
            begin++;
            expr(begin);
        }
    }
    else
    {
        ret = "set";
        while (*begin != '}')
        {
            begin++;
            expr(begin);
        }
    }
    return ret;
}

int main()
{
    string s;
    cin >> s;
    if (s == "{}")
    {
        cout << "dict" << endl;
    }
    else
    {
        State begin = s.begin();
        cout << set_or_dict(begin) << endl;
    }

    return 0;
}