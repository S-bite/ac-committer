#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
typedef pair<int, int> P;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;
int n, p, m;
std::random_device rnd;
std::mt19937 mt(rnd());

/*
map<P, vector<P>> makeGraph(vector<vector<char>> &tilem, char t)
{

}*/

int main(int argc, char const *argv[])
{
    cin >> n >> p >> m;
    vector<vector<char>> tile(n, vector<char>(n, '@'));
    vector<vector<bool>> wall(n, vector<bool>(n, false));
    int roboy, robox;
    map<char, int> num;
    rep(i, n)
    {
        string s;
        cin >> s;
        rep(j, n)
        {
            if (s[j] == 'x')
            {
                wall[i][j] = true;
            }
            if (s[j] == 'o')
            {
                roboy = i;
                robox = j;
            }
        }
        rep(i, n) rep(j, n)
        {
            cin >> tile[i][j];
            num[tile[i][j]]++;
        }
    }
    vector<pair<int, char>> v;
    rep(i, 'A', 'Z' + 1)
    {
        v.push_back({num[i], (char)i});
    }
    sort(ALL(v), greater<pair<int, char>>());
    char dir[4] = {'U', 'D', 'L', 'R'};

    rep(i, m)
    {
        cout << dir[mt() % 4] << endl;
    }
    return 0;
}
