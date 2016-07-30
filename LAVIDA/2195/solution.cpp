#include <stdio.h>
#include <memory.h>

#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

ll dp[100003][2];

vector < pair <int, int> > lod;
vector < int > mapp[2];

int vfind(int key, int val){
	int l = 0, r = mapp[key].size() - 1, m;

	while (l <= r){
		m = (l + r) / 2;
		if (mapp[key][m] < val)l = m + 1;
		else if (mapp[key][m] > val)r = m - 1;
		else
			return m;
	}
}

int main(){

	int n, L;
	scanf("%d %d", &n, &L);

	for (int i = 0; i < n; i++){
		int t, d;
		scanf("%d %d", &t, &d);
		mapp[0].push_back(t);
		mapp[1].push_back(d);
		lod.push_back(make_pair(t, d));
	}

	for (int i = 0; i < 2; i++){
		sort(mapp[i].begin(), mapp[i].end());
		mapp[i].resize(distance(mapp[i].begin(), unique(mapp[i].begin(), mapp[i].end())));
	}

	sort(lod.begin(), lod.end());

	ll ans = 0;

	for (int i = 0; i < lod.size() /* = N */; i++){

		ll len = abs(lod[i].first - lod[i].second) + L;

		ll up = dp[vfind(1, lod[i].second)][1] + len;
		ll down = dp[vfind(0, lod[i].first)][0] + len;

		ans = max(ans, max(up, down));

		if (dp[vfind(0, lod[i].first)][0] < up)dp[vfind(0, lod[i].first)][0] = up;
		if (dp[vfind(1, lod[i].second)][1] < down)dp[vfind(1, lod[i].second)][1] = down;

	}

	printf("%lld\n", ans);

}