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
};
void printsushi(sushi s[], int n)
{
    rep(i, n)
    {
        cout << "id:" << s[i].id << ",delicious:" << s[i].delicious << ",type:" << s[i].type << endl;
    }
}
bool cmp(const sushi &a, const sushi &b)
{
    return a.delicious > b.delicious;
}
int main()
{
    int n, k;
    cin >> n >> k;
    sushi s[n], tops[n];
    rep(i, n) tops[i] = sushi{0, -1, -1};
    rep(i, n)
    {
        int t, d;
        cin >> t >> d;
        sushi nsushi = sushi{d, t, i};
        s[i] = nsushi;
        tops[s[i].type - 1] = min(tops[s[i].type - 1], nsushi, cmp);
    }
    sort(s, s + n, cmp);
    sort(tops, tops + n, cmp);
    printsushi(tops, n);
    ll ans = 0;
    for (int i = 0; i <= k; i++)
    {
        map<int, int> mp;
        map<int, bool> eaten;
        ll tans = 0;
        int count = 0;
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
            if (eaten[s[j].id])
            {
                continue;
            }
            tans += s[j].delicious;
            mp[s[j].type]++;
            eaten[s[j].id] = true;
            count++;
        }
        tans += (ll)mp.size() * mp.size();
        ans = max(ans, tans);
    }
    cout << ans << endl;
    return 0;
}