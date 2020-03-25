#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <climits>
#include <functional>
#include <queue>
#include <cmath>
#include <utility>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define rep1(i,n) for(int i=1;i<=(int)n;++i)

int N;
int a[300010];
int scoreL[100010], scoreR[100010];

signed main()
{
	cin >> N;

	rep(i, N*3) cin >> a[i];

	priority_queue<int, vector<int>, greater<int>> L;
	priority_queue<int> R;

	int sumL = 0, sumR = 0;
	for (int i = 0; i < N; ++i) {
		L.push(a[i]);
		sumL += a[i];
	}
	for (int i = N * 2; i < N * 3; ++i) {
		R.push(a[i]);
		sumR += a[i];
	}

	scoreL[0] = sumL;
	scoreR[0] = sumR;
	int l = N, r = N * 2 - 1;
	for (int i = 1; i <= N; ++i) {
		sumL -= L.top(); L.pop();
		sumL += a[l];
		L.push(a[l]);
		scoreL[i] = sumL;

		sumR -= R.top(); R.pop();
		sumR += a[r];
		R.push(a[r]);
		scoreR[i] = sumR;

		l++, r--;
	}

	int ans = -1;

	for (int i = 0; i <= N; ++i) {
		ans = max(ans, scoreL[i] - scoreR[N-i]);
	}

	cout << ans << endl;
}
