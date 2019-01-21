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

    sort(tt, tt + n, greater<sushi>());

    ll ans = 0;
    for (int i = 1; i <= k; i++)
    {
        map<int, int> mp;
        map<int, bool> eaten;
        ll tans = 0;
        int count = 0;
        priority_queue<sushi> t = s; //, ttops = tops;
        rep(j, i)
        {
            sushi tsushi = tt[j]; //ttops.top();
            //ttops.pop();
            if (tsushi.id == -1)
            {
                cout << ans << endl;
                return 0;
            }
            tans += tsushi.delicious;
            mp[tsushi.type]++;
            eaten[tsushi.id] = true;
            count++;
        }
        for (int j = i; count < k; j++)
        {
            sushi ss = t.top();
            t.pop();
            if (eaten[ss.id])
            {
                continue;
            }
            tans += ss.delicious;
            mp[ss.type]++;
            eaten[ss.id] = true;
            count++;
        }

        tans += (ll)mp.size() * (ll)mp.size();
        ans = max(ans, tans);
    }
    cout << ans << endl;
    return 0;
}