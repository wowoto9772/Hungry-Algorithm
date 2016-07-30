//#include <stdio.h>
//#include <memory.h>
//
//#include <map>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//#define ll long long
//
//int p[100003][2];
//ll dp[100003][2];
//
//vector < int > mapp[2];
//vector < vector <int> > down, up;
//
//int vfind(int key, int val){
//	int l = 0, r = mapp[key].size() - 1, m;
//
//	while (l <= r){
//		m = (l + r) / 2;
//		if (mapp[key][m] < val)l = m + 1;
//		else if (mapp[key][m] > val)r = m - 1;
//		else
//			return m;
//	}
//}
//
//int L;
//
//bool stk[100003][2];
//
//map <int, map <int, bool> > chk;
//
//ll dy(int d, int p){
//	
//	if (dp[d][p] != -1)return dp[d][p];
//
//	stk[d][p] = true;
//
//	dp[d][p] = 0;
//
//	if (p == 0){
//
//		for (int i = 0; i < down[d].size(); i++){
//
//			int e = down[d][i];
//
//			if (chk[d][e])continue;
//			chk[d][e] = chk[e][d] = true;
//
//			dp[d][p] = max(dp[d][p], L + abs(mapp[0][d] - mapp[1][e]) + dy(e, !p));
//
//		}
//
//	}
//	else{
//
//		for (int i = 0; i < up[d].size(); i++){
//
//			int e = up[d][i];
//
//			if (chk[d][e])continue;
//			chk[d][e] = chk[e][d] = true;
//
//			dp[d][p] = max(dp[d][p], L + abs(mapp[1][d] - mapp[0][e]) + dy(e, !p));
//
//		}
//
//	}
//
//	stk[d][p] = false;
//
//	return dp[d][p];
//
//}
//
//int main(){
//
//	int n;
//	scanf("%d %d", &n, &L);
//
//	for (int i = 0; i < n; i++){
//		scanf("%d %d", &p[i][0], &p[i][1]);
//		mapp[0].push_back(p[i][0]);
//		mapp[1].push_back(p[i][1]);
//	}
//
//	for (int i = 0; i < 2; i++){
//		sort(mapp[i].begin(), mapp[i].end());
//		mapp[i].resize(distance(mapp[i].begin(), unique(mapp[i].begin(), mapp[i].end())));
//		if (!i)down.resize(mapp[i].size());
//		else
//			up.resize(mapp[i].size());
//	}
//
//	for (int i = 0; i < n; i++){
//		down[vfind(0, p[i][0])].push_back(vfind(1, p[i][1]));
//		up[vfind(1, p[i][1])].push_back(vfind(0, p[i][0]));
//	}
//
//	ll ans = 0;
//
//	memset(dp, 0xff, sizeof(dp));
//
//	for (int i = 0; i < n; i++){
//
//		ans = max(ans, max(dy(vfind(1, p[i][1]), 1), dy(vfind(0, p[i][0]), 0)));
//
//	}
//
//	printf("%lld\n", ans);
//
//}

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