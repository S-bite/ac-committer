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

int main()
{
    int n, k;
    clock_t c = clock();
    cin >> n >> k;
    sushi tt[n];
    priority_queue<sushi> s, tops;
    rep(i, n) tt[i] = sushi{-1, -1, -1};
    rep(i, n)
    {
        int t, d;
        cin >> t >> d;
        sushi nsushi = sushi{d, t, i};
        s.push(nsushi);
        tt[nsushi.type - 1] = max(tt[nsushi.type - 1], nsushi);
    }
    //    sort(s, s + n, greater<sushi>());

    rep(i, n) tops.push(tt[i]);

    ll ans = 0, tans = 0, ttans = 0;
    map<int, bool> eaten;
    map<int, int> mp, tmp;
    sushi tsushi;

    for (int i = 1; i <= k; i++)
    {

        int count = i;
        priority_queue<sushi> t = s;

        tsushi = tops.top();
        tops.pop();
        if (tsushi.id == -1)
        {
            cout << ans << endl;
            return 0;
        }
        ttans += tsushi.delicious;
        tmp[tsushi.type]++;
        eaten[tsushi.id] = true;
        tans = ttans;
        mp = tmp;
        bool f = false;
        for (int j = i; count < k; j++)
        {
            if (t.empty())
            {
                f = true;
                break;
            }
            sushi ss = t.top();
            t.pop();
            if (eaten[ss.id] || mp.find(ss.type) == end(mp))
            {
                continue;
            }
            tans += ss.delicious;
            mp[ss.type]++;
            count++;
        }
        if (f)
            continue;
        tans += (ll)mp.size() * (ll)mp.size();
        ans = max(ans, tans);
        if ((double(clock() - c) / CLOCKS_PER_SEC > 1.8))
            break;
    }
    cout << ans << endl;
    return 0;
}