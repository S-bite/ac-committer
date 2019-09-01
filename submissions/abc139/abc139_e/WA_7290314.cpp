#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;
int main(int argc, char const *argv[])
{

    clock_t starttime = clock();
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n - 1));
    vector<int> ind(n, 0);
    vector<bool> isok(n, true);
    int ans = 0;
    int cnt = 0;
    bool f = true;
    rep(i, n)
    {
        rep(j, n - 1)
        {
            scanf("%d", &v[i][j]);
            v[i][j]--;
        }
    }
    vector<pair<int, int>> p(n);
    rep(i, n) p[i] = {0, i};
    while (cnt < n * (n - 1) / 2 && f)
    {
        f = false;
        vector<bool> usedturn(n, false);
        vector<vector<bool>> used(n, vector<bool>(n - 1, false));

        rep(i, n)
        {
            int cur = p[i].second;

            if (ind[cur] == n - 1)
            {
                if (i == 0)
                {
                    cout << ans + 1 << endl;
                    return 0;
                }
                break;
            }
            int next = v[cur][ind[cur]];

            if (usedturn[cur] == true || usedturn[next] == true)
            {
                continue;
            }
            if (ind[next] == n - 1)
            {
                continue;
            }

            if (v[next][ind[next]] != cur)
            {
                continue;
            }
            //cerr << "turn " << ans << " " << cur + 1 << "," << next + 1 << " " << cnt << endl;

            usedturn[next] = true;
            usedturn[cur] = true;
            used[next][next] = true;
            used[cur][next] = true;
            ind[cur]++;
            ind[next]++;
            cnt += 1;
            f = true;
            p[cur].first++;
            p[next].first++;
        }
        sort(ALL(p));

        ans++;
    }
    cerr << ans << endl;
    if (f == false)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", ans);
    return 0;
}
