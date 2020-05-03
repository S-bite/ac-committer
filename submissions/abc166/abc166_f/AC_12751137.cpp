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
int n;
vector<string> q;
vector<string> ans;
void dfs(int cur, int a, int b, int c)
{
    if (a < 0 || b < 0 || c < 0)
        return;
    if (cur == n)
    {
        cout << "Yes" << endl;
        for (auto &&x : ans)
        {
            cout << x << endl;
        }
        exit(0);
    }
    if (q[cur] == "AB")
    {
        if (a == b)
        {
            a++;
            b--;
            ans.push_back("A");
            dfs(cur + 1, a, b, c);
            ans.pop_back();
            a--;
            b++;

            a--;
            b++;
            ans.push_back("B");
            dfs(cur + 1, a, b, c);
            ans.pop_back();
        }
        else if (a < b)
        {
            a++;
            b--;
            ans.push_back("A");
            dfs(cur + 1, a, b, c);
            ans.pop_back();
        }
        else
        {

            a--;
            b++;
            ans.push_back("B");
            dfs(cur + 1, a, b, c);
            ans.pop_back();
        }
    }
    else if (q[cur] == "AC")
    {
        if (a == c)
        {
            a++;
            c--;
            ans.push_back("A");
            dfs(cur + 1, a, b, c);
            ans.pop_back();

            a--;
            c++;
            a--;
            c++;
            ans.push_back("C");
            dfs(cur + 1, a, b, c);
            ans.pop_back();
        }
        else if (a < c)
        {
            a++;
            c--;
            ans.push_back("A");
            dfs(cur + 1, a, b, c);
            ans.pop_back();
        }
        else
        {

            a--;
            c++;
            ans.push_back("C");
            dfs(cur + 1, a, b, c);
            ans.pop_back();
        }
    }
    else
    {
        if (b == c)
        {
            b++;
            c--;
            ans.push_back("B");
            dfs(cur + 1, a, b, c);
            ans.pop_back();

            b--;
            c++;
            b--;
            c++;
            ans.push_back("C");
            dfs(cur + 1, a, b, c);
            ans.pop_back();
        }
        else if (b < c)
        {
            b++;
            c--;
            ans.push_back("B");
            dfs(cur + 1, a, b, c);
            ans.pop_back();
        }
        else
        {
            b--;
            c++;
            ans.push_back("C");
            dfs(cur + 1, a, b, c);
            ans.pop_back();
        }
    }
}

int main()
{
    int a, b, c;
    cin >> n;
    cin >> a >> b >> c;
    rep(i, n)
    {
        string s;
        cin >> s;
        q.push_back(s);
    }
    dfs(0, a, b, c);
    cout << "No" << endl;

    return 0;
}