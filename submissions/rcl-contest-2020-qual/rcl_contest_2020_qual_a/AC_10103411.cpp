#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
class Tactics
{
public:
    int score;
    Tactics()
    {
    }
    ~Tactics() {}
};
bool operator>(const Tactics &t1, const Tactics &t2)
{
    return t1.score > t2.score;
};
int main(int argc, char const *argv[])
{
    int n, w, k, v;
    cin >> n >> w >> k >> v;
    vector<pair<int, int>> monomino(n);
    rep(i, n) cin >> monomino[i].second >> monomino[i].first;
    int currrent_color = -1;
    int current_pos = 0;
    deque<int> que;
    rep(i, n)
    {
        if (currrent_color == -1)
        {
            currrent_color = monomino[i].second;
        }
        if (monomino[i].second == currrent_color)
        {
            cout << current_pos << endl;
            current_pos++;
            if (current_pos == w)
            {
                current_pos = 0;
                currrent_color = -1;
            }
        }
        else
        {

            cout << current_pos - 1 << endl;
            que.push_back(monomino[i].second);
        }
    }

    return 0;
}
