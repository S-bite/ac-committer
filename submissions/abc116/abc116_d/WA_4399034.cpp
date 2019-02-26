#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int N, K;
    cin >> N >> K;
    pair<ll, int> A[N];
    for (int i = 0; i < N; i++)
    {
        ll t, d;
        cin >> t >> d;
        A[i] = {d, t};
    }
    sort(A, A + N);
    reverse(A, A + N);
    ll ans = 0, sum = 0;
    map<int, int> mp; //map<寿司の種類番号、その数>
    for (int i = 0; i < K; i++)
    {
        sum += A[i].first;
        mp[A[i].second]++;
    }
    int s = mp.size();
    ans = sum + s * s;

    int r = K - 1; //集合から追い出す要素を指すインデックス
    for (int i = K; i < N; i++)
    {
        if (mp[A[i].second] == 0)
        {

            while (mp[A[r].second] == 1 && r >= 0)
                r--;
            if (r == -1)
                break;
            mp[A[i].second]++;
            s++; //食べていない種類の寿司を食べたのでインクリメント
            sum += A[i].first - A[r].first;
            mp[A[r].second]--;
            if (mp[A[r].second] == 0) //寿司の種類数が0になったらデクリメント
                s--;
            ans = max(ans, sum + s * s);
        }
    }

    cout << ans << endl;
}