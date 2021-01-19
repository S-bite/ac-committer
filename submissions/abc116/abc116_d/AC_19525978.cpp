#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
random_device rnd;
mt19937 mt(rnd());
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;

struct Sushi
{
    ll deliciousness;
    int kind;
};
bool operator<(const Sushi &x, const Sushi &y) { return x.deliciousness < y.deliciousness; };
bool operator>(const Sushi &x, const Sushi &y) { return x.deliciousness > y.deliciousness; };

struct SushiInfo
{
    ll totalDeliciousness;
    int kind;
    int amount;
    bool operator<(const SushiInfo &x) { return totalDeliciousness < x.totalDeliciousness; };
    bool operator>(const SushiInfo &x) { return totalDeliciousness > x.totalDeliciousness; };
};

void compress(vector<int> &v)
{
    map<int, int> mp;
    int next = 0;
    for (auto &x : v)
    {
        if (mp.find(x) == mp.end())
        {
            mp[x] = next++;
        }
        x = mp[x];
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<Sushi> sushi(n);
    vector<int> tmp;

    rep(i, n)
    {
        cin >> sushi[i].kind >> sushi[i].deliciousness;
        tmp.push_back(sushi[i].kind);
    }
    compress(tmp);
    int netaKindNum = -1;
    rep(i, n)
    {
        sushi[i].kind = tmp[i];
        chmax(netaKindNum, tmp[i] + 1);
    }
    vector<int> netacount(netaKindNum, 0);
    rep(i, netaKindNum)
    {
        netacount[tmp[i]]++;
    }
    priority_queue<Sushi> sushiPque;
    auto sum = vector<int>(netaKindNum, 0);
    rep(i, n)
    {
        sum[sushi[i].kind] += sushi[i].deliciousness;
        sushiPque.push(sushi[i]);
    }

    vector<Sushi> ansVec;
    set<int> ansKind;
    map<int, int> ansNetaCount;
    ll base = 0;
    ll typeBonus = 0;
    rep(i, k)
    {
        auto cur = sushiPque.top();
        sushiPque.pop();
        ansVec.push_back(cur);
        ansKind.insert(cur.kind);
        ansNetaCount[cur.kind]++;
        base += cur.deliciousness;
    }
    typeBonus = ansKind.size();
    sort(ALL(ansVec), greater<Sushi>());
    ll ans = base + typeBonus * typeBonus;
    // cerr << 123 << endl;
    while (!sushiPque.empty() && !ansVec.empty())
    {
        //cerr << sushiPque.size() << " " << ansVec.size() << endl;
        auto drop = ansVec.back();
        ansVec.pop_back();
        if (ansNetaCount[drop.kind] == 1)
            continue;
        base -= drop.deliciousness;
        while (!sushiPque.empty())
        {
            // cerr << sushiPque.size() << " " << ansVec.size() << endl;
            if (ansKind.find(sushiPque.top().kind) != ansKind.end())
            {
                sushiPque.pop();
            }
            else
            {
                break;
            }
        }
        if (sushiPque.empty())
        {
            break;
        }
        auto in = sushiPque.top();
        sushiPque.pop();
        base += in.deliciousness;
        ansNetaCount[in.kind]++;
        ansKind.insert(in.kind);
        typeBonus++;
        chmax(ans, base + typeBonus * typeBonus);
    }
    cout << ans << endl;
    return 0;
}
