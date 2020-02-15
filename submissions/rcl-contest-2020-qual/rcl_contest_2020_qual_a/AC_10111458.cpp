#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
std::random_device rnd;
std::mt19937 mt(rnd());

class Tactics
{
public:
    int score;
    vector<int> order;

    Tactics()
    {
    }
    ~Tactics() {}
};
bool operator<(const Tactics &t1, const Tactics &t2)
{
    return t1.score < t2.score;
};

void eval_diff(Tactics &tact, vector<pair<int, int>> &monomino, int r1, int r2)
{
}

void eval(Tactics &tact, vector<pair<int, int>> &monomino)
{
    vector<vector<int>> g(1000, vector<int>(8, -1));
    vector<vector<int>> s(1000, vector<int>(8, -1));

    vector<int> cur_height(8, 0);
    tact.score = 0;
    rep(i, 1000)
    {
        int pos = tact.order[i];
        g[cur_height[pos]][pos] = monomino[i].second;
        s[cur_height[pos]][pos] = monomino[i].first;

        cur_height[pos]++;
    }
    rep(i, 1000)
    {
        bool flag = true;
        vector<int> num(8, 0);
        vector<int> score(8, 0);

        rep(j, 8)
        {
            if (g[i][j] == -1)
            {
                flag = false;
                break;
            }
            score[g[i][j]] += s[i][j];
            num[g[i][j]]++;
        }
        if (flag == false)
            break;
        int t = max_element(ALL(num)) - num.begin();
        tact.score += score[t];
    }
}

int main(int argc, char const *argv[])
{

    clock_t starttime = clock();
    int n, w, k, v;
    cin >> n >> w >> k >> v;
    vector<pair<int, int>> monomino(n);
    rep(i, n) cin >> monomino[i].second >> monomino[i].first;
    int currrent_color = -1;
    int current_pos = 0;
    priority_queue<Tactics> pque;
    rep(_, 500)
    {

        Tactics t;
        int pos = 0;
        rep(i, n)
        {
            t.order.push_back(i % w);
        }
        shuffle(ALL(t.order), mt);
        eval(t, monomino);
        pque.push(t);
    }

    int cnt = 0;

    while (double(clock() - starttime) / CLOCKS_PER_SEC < 1.9)
    {

        auto tmp = pque;
        while (!pque.empty())
        {
            Tactics tact = pque.top();
            pque.pop();
            int r1, r2;
            int p = 10 + mt() % 8;
            do
            {
                r1 = mt() % (n - p);
                r2 = r1 + mt() % (p);
            } while (tact.order[r1] == tact.order[r2]);
            swap(tact.order[r1], tact.order[r2]);
            eval(tact, monomino);
            tmp.push(tact);
        }
        rep(i, min((int)tmp.size(), 3))
        {
            pque.push(tmp.top());
            tmp.pop();
        }
        cnt++;
    }
    auto best = pque.top();
    rep(i, n)
    {
        cout << best.order[i] << endl;
    }
    cerr << "loop num:" << cnt << endl;
    cerr << "score:" << best.score << endl;

    return 0;
}
