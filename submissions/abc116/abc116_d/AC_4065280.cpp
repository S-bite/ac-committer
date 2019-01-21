#include <bits/stdc++.h>
#define ll unsigned long long
#define fir first
#define sec second
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
struct sushi
{
    int delicious;
    int type;
    int id;
    bool operator<(const sushi &another) const
    {
        return delicious < another.delicious;
    };
    bool operator>(const sushi &another) const
    {
        return delicious > another.delicious;
    };
};
void printsushi(sushi s[], int n)
{
    rep(i, n)
    {
        cout << "id:" << s[i].id << ",delicious:" << s[i].delicious << ",type:" << s[i].type << endl;
    }
}

ll eval(priority_queue<sushi, vector<sushi>, greater<sushi>> base, priority_queue<sushi, vector<sushi>, greater<sushi>> opt, int mpsize)
{
    auto evbase = base, evopt = opt;
    ll ret = 0;
    while (!evbase.empty())
    {
        ret += evbase.top().delicious;
        evbase.pop();
    }
    while (!evopt.empty())
    {
        ret += evopt.top().delicious;
        evopt.pop();
    }
    ret += (ll)mpsize * (ll)mpsize;
    return ret;
}

int main()
{
    int n, k;
    clock_t c = clock();
    cin >> n >> k;
    sushi tt[n];
    priority_queue<sushi> all;
    priority_queue<sushi, vector<sushi>, greater<sushi>> base, opt;

    rep(i, n) tt[i] = sushi{0, -1, -1};
    rep(i, n)
    {
        int t, d;
        cin >> t >> d;
        sushi nsushi = sushi{d, t, i};
        all.push(nsushi);
        tt[nsushi.type - 1] = max(tt[nsushi.type - 1], nsushi);
    }
    map<int, bool> mp;
    rep(i, k)
    {
        sushi s = all.top();
        all.pop();
        if (mp.find(s.type) == end(mp))
        {
            base.push(s);
            mp[s.type] = true;
        }
        else
        {
            opt.push(s);
        }
    }
    priority_queue<ll> ans;
    ans.push(eval(base, opt, mp.size()));
    ll nowans = ans.top();
    while (!all.empty() && mp.size() != k)
    {
        sushi s = all.top();
        all.pop();
        if (mp.find(s.type) != end(mp))
            continue;
        mp[s.type] = true;
        int lossdesicious = opt.top().delicious, gaindelicious = s.delicious, ms = mp.size();
        opt.pop();
        base.push(s);
        nowans = nowans - lossdesicious + gaindelicious - (ms - 1) * (ms - 1) + ms * ms;
        ans.push(nowans);
    }
    cout << ans.top() << endl;
    return 0;
}
