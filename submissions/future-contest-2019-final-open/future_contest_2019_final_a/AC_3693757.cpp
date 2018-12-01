#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ll long long
#define MNUM 30000
using namespace std;
class Misson
{

  public:
    ll reward;
    int start, end;
    int rskills[10];
    Misson()
    {
    }
    void init()
    {
        scanf("%d", &start);
        scanf("%d", &end);
        scanf("%lld", &reward);
        rep(i, 10) scanf("%d", &rskills[i]);
    }
};

pair<ll, int> maxreward(int turn, int skills[10], Misson m[MNUM], bool getbefore[MNUM])
{
    ll ret = -1.0;
    int index = -1;
    int rend = 1001;
    rep(i, MNUM)
    {
        //      cout << i << endl;
        if (m[i].start > turn || m[i].end < turn || getbefore[i])
        {
            continue;
        }
        //        cout << "1" << endl;
        double pskill = 0.0;
        rep(j, 10)
        {
            pskill += max(0, m[i].rskills[j] - skills[j]);
        }
        if (pskill == 0.0)
            pskill = 10.0;
        else
            pskill = powf(0.5, pskill);
        double pturn = 1.0 + 9.0 * ((double)(turn - m[i].start)) / ((double)(m[i].end - m[i].start));
        double nreward = ((double)m[i].reward) * pskill * pturn;

        if ((nreward > 1000) && rend > m[i].end)
        {
            ret = (ll)nreward;
            index = i;
            rend = m[i].end;
        }
    }
    return pair<ll, int>{ret, index};
}

pair<ll, int> skillupdate(ll &money, int (&skills)[10], int (&skillsexp)[10])
{
    rep(i, 10)
    {
        if ((skills[i] == 10 and i != 1) or (i == 1 and skills[i] == 10))
            continue;
        ll cost = 10000 * pow(2, skills[i] + 1);
        if (money > cost * (1 + skills[i] - skillsexp[i]))
        {
            return pair<ll, int>{cost, i};
        }
    }
    return pair<ll, int>{0, -1};
}

int main()
{
    int t, n, m;
    cin >> t >> n >> m;
    Misson missons[MNUM];
    bool getbefore[MNUM] = {false};
    rep(i, MNUM)
    {
        missons[i].init();
    };
    int skills[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int skillsexp[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    ll money = 1000;
    for (int i = 1; i <= t; i++)
    {
        //cout << money << endl;
        pair<ll, int> trainpair = skillupdate(money, skills, skillsexp);
        if (trainpair.second != -1 && i < 1000)
        {
            ll cost = trainpair.first;
            int index = trainpair.second;

            cout << 1 << " " << (index + 1) << endl;
            money -= cost;
            skillsexp[index]++;
            if (skillsexp[index] == skills[index] + 1)
            {
                skills[index]++;
                skillsexp[index] = 0;
            }
            continue;
        }
        pair<ll, int> rewardpair = maxreward(i, skills, missons, getbefore);
        if (rewardpair.first != -1)
        {
            cout << 2 << " " << (rewardpair.second + 1) << endl;
            getbefore[rewardpair.second] = true;
            money += rewardpair.first;
            continue;
        }

        else
        {
            cout << 3 << endl;
            money += 1000;
            continue;
        }
    }
  
}