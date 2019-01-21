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
    sushi tops[n];
    priority_queue<sushi> s;
    rep(i, n) tops[i] = sushi{0, -1, -1};
    rep(i, n)
    {
        int t, d;
        cin >> t >> d;
        sushi nsushi = sushi{d, t, i};
        s.push(nsushi);
        tops[nsushi.type - 1] = max(tops[nsushi.type - 1], nsushi);
    }
    //sort(s, s + n, greater<sushi>());
    sort(tops, tops + n, greater<sushi>());
    reverse(tops, tops + n);

    ll ans = 0;
    for (int i = 0; i <= k; i++)
    {
        map<int, int> mp;
        map<int, bool> eaten;
        ll tans = 0;
        int count = 0;
        priority_queue<sushi> t = s;
        rep(j, i)
        {
            if (tops[j].id == -1)
            {
                cout << ans << endl;
                return 0;
            }

            tans += tops[j].delicious;
            mp[tops[j].type]++;
            eaten[tops[j].id] = true;
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
        tans += (ll)mp.size() * mp.size();
        ans = max(ans, tans);
    }
    cout << ans << endl;
    return 0;
}