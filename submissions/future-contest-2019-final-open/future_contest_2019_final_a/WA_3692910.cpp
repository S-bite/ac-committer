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
        cin >> start;
        cin >> end;
        cin >> reward;
        rep(i, 10) cin >> rskills[i];
    }
};
bool cmpbystart(Misson a, Misson b)
{
    return a.start < b.start;
}
bool cmpbyend(Misson a, Misson b)
{
    return a.end < b.end;
}

vector<Misson> gettablemissons(int turn, vector<Misson> m)
{
    vector<Misson> ret;
    for (auto it = begin(m); it != end(m); ++it)
    {
        cout << (*it).start << "," << (*it).end << endl;
        if ((*it).start > turn)
            break;
        if ((*it).end >= turn)
            ret.push_back(*it);
    }

    return ret;
}

pair<ll, int> maxreward(int turn, int skills[10], Misson m[MNUM], bool getbefore[MNUM])
{
    ll ret = -1.0;
    int index = -1;
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
            pskill = 1.0 / pow(2, pskill);
        double pturn = 1.0 + ((double)(turn - m[i].start)) / ((double)(m[i].end - m[i].start));
        double nreward = (double)m[i].reward * pskill * pturn;
        if (nreward > ret)
        {
            ret = (ll)nreward;
            index = i;
        }
    }
    return pair<ll, int>{ret, index};
}

pair<ll, int> skillupdate(ll &money, int (&skills)[10], int (&skillsexp)[10])
{
    rep(i, 10)
    {
        if (skills[i] == 10)
            continue;
        ll cost = 10000 * pow(2, skills[i]);
        if (money > cost)
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
    rep(i, 1000)
    {
        pair<ll, int> trainpair = skillupdate(money, skills, skillsexp);
        if (trainpair.second != -1)
        {
            ll cost = trainpair.first;
            int index = trainpair.second;

            cout << 1 << " " << index << endl;
            money -= cost;
            skillsexp[index]++;
            if (skillsexp[index] == skills[index] + 1)
            {
                skills[index]++;
                skillsexp[index] = 0;
            }
            continue;
        }

        pair<ll, int> rewardpair = maxreward(1, skills, missons, getbefore);
        if (rewardpair.first >= 1000)
        {
            cout << 2 << " " << rewardpair.second << endl;
            getbefore[rewardpair.second] = true;
        }
        else
        {
            cout << 3 << endl;
            money += 1000;
        }
    }
}