//#include <stdio.h>
//#include <limits.h>
//
//#include <algorithm>
//#include <vector>
//
//#define ll long long
//
//using namespace std;
//
//ll c[1003], p[1003];
//
//int n;
//
//int lfind(int a){
//
//	int s = 0;
//
//	for (int i = 0; i < n; i++){
//		if (p[i] < a)s = i;
//		else
//			break;
//	}
//
//	return s;
//
//}
//
//int rfind(int a){
//
//	int s = n - 1;
//
//	for (int i = n - 1; i >= 0; i--){
//		if (p[i] > a)s = i;
//		else
//			break;
//	}
//
//	return s;
//}
//
//ll dp[1003][1003][2], cur[1003][1003][2];
//
//int main(){
//
//	int x;
//	scanf("%d %d", &n, &x);
//
//	vector <int> tmp;
//	for (int i = 0; i < n; i++){
//		scanf("%d", &p[i]);
//		tmp.push_back(p[i]);
//	}
//
//	sort(tmp.begin(), tmp.end());
//	tmp.resize(distance(tmp.begin(), unique(tmp.begin(), tmp.end())));
//
//	for (int i = 0; i < n; i++){
//		int l = 0, r = tmp.size() - 1, m;
//		while (l <= r){
//			m = (l + r) / 2;
//			if (tmp[m] == p[i]){
//				c[m]++;
//				break;
//			}
//			else if (tmp[m] < p[i]){
//				l = m + 1;
//			}
//			else if (tmp[m] > p[i]){
//				r = m - 1;
//			}
//		}
//	}
//
//	for (int i = 0; i < tmp.size(); i++)p[i] = tmp[i];
//	n = tmp.size();
//
//	int l = lfind(x), r = rfind(x);
//
//	for (int i = 0; i < n; i++){
//		for (int j = i; j < n; j++){
//			dp[i][j][0] = dp[i][j][1] = LLONG_MAX;
//		}
//	}
//
//	dp[l][l][0] = dp[l][l][1] = abs(x - p[l]) * c[l];
//	cur[l][l][0] = cur[l][l][1] = abs(x - p[l]);
//	dp[r][r][1] = dp[r][r][1] = abs(p[r] - x) * c[r];
//	cur[r][r][0] = cur[r][r][1] = abs(p[r] - x);
//
//	for (int k = 1; k < n; k++){
//		for (int i = 0; i + k < n; i++){
//			int j = i + k;
//			ll cst, ccst;
//			if (dp[i][j - 1][1] != LLONG_MAX){ // right to right
//				ccst = cur[i][j - 1][1] + (p[j] - p[j - 1]);
//				cst = dp[i][j - 1][1] + ccst * c[j];
//				if (dp[i][j][1] > cst){
//					cur[i][j][1] = ccst;
//					dp[i][j][1] = cst;
//				}
//				else if (dp[i][j][1] == cst && cur[i][j][1] > ccst){
//					cur[i][j][1] = ccst;
//				}
//			}
//			if (dp[i][j - 1][0] != LLONG_MAX){ // left to right
//				ccst = cur[i][j - 1][0] + p[j] - p[i];
//				cst = dp[i][j - 1][0] + ccst * c[j];
//				if (dp[i][j][1] > cst){
//					cur[i][j][1] = ccst;
//					dp[i][j][1] = cst;
//				}
//				else if (dp[i][j][1] == cst && cur[i][j][1] > ccst){
//					cur[i][j][1] = ccst;
//				}
//			}
//			if (dp[i + 1][j][0] != LLONG_MAX){ // left to left
//				ccst = cur[i + 1][j][0] + (p[i + 1] - p[i]);
//				cst = dp[i + 1][j][0] + ccst * c[i];
//				if (dp[i][j][0] > cst){
//					cur[i][j][0] = ccst;
//					dp[i][j][0] = cst;
//				}
//				else if (dp[i][j][0] == cst && cur[i][j][0] > ccst){
//					cur[i][j][0] = ccst;
//				}
//			}
//			if (dp[i + 1][j][1] != LLONG_MAX){ // right to left
//				ccst = cur[i + 1][j][1] + (p[j] - p[i]);
//				cst = dp[i + 1][j][1] + ccst * c[i];
//				if (dp[i][j][0] > cst){
//					cur[i][j][0] = ccst;
//					dp[i][j][0] = cst;
//				}
//				else if (dp[i][j][0] == cst && cur[i][j][0] > ccst){
//					cur[i][j][0] = ccst;
//				}
//			}
//		}
//	}
//
//	printf("%lld\n", min(dp[0][n - 1][0], dp[0][n - 1][1]));
//
//}

#include <stdio.h>
#include <limits.h>

#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

ll c[1003], p[1003];

int n;

int lfind(int a){

	int s = 0;

	for (int i = 0; i < n; i++){
		if (p[i] < a)s = i;
		else
			break;
	}

	return s;

}

int rfind(int a){

	int s = n - 1;

	for (int i = n - 1; i >= 0; i--){
		if (p[i] > a)s = i;
		else
			break;
	}

	return s;
}

ll dp[1003][1003][2];

ll dy(int l, int r, int ri){

	if (!l && r == n - 1)return 0;
	if (dp[l][r][ri] != -1)return dp[l][r][ri];

	ll c = n - (r - l + 1);

	dp[l][r][ri] = LLONG_MAX;

	if (!ri){ // left
		if (l)dp[l][r][ri] = dy(l - 1, r, ri) + (p[l] - p[l - 1]) * c;
		if (r < n - 1)dp[l][r][ri] = min(dp[l][r][ri], dy(l, r + 1, !ri) + (p[r + 1] - p[l]) * c);
	}
	else{ // right
		if (l)dp[l][r][ri] = dy(l - 1, r, !ri) + (p[r] - p[l - 1]) * c;
		if (r < n - 1)dp[l][r][ri] = min(dp[l][r][ri], dy(l, r + 1, ri) + (p[r + 1] - p[r]) * c);
	}

	return dp[l][r][ri];

}

int main(){

	int x;
	scanf("%d %d", &n, &x);

	vector <int> tmp;
	for (int i = 0; i < n; i++){
		scanf("%d", &p[i]);
		tmp.push_back(p[i]);
	}

	sort(tmp.begin(), tmp.end());
	tmp.resize(distance(tmp.begin(), unique(tmp.begin(), tmp.end())));

	for (int i = 0; i < n; i++){
		int l = 0, r = tmp.size() - 1, m;
		while (l <= r){
			m = (l + r) / 2;
			if (tmp[m] == p[i]){
				c[m]++;
				break;
			}
			else if (tmp[m] < p[i]){
				l = m + 1;
			}
			else if (tmp[m] > p[i]){
				r = m - 1;
			}
		}
	}

	for (int i = 0; i < tmp.size(); i++)p[i] = tmp[i];
	n = tmp.size();

	int l = lfind(x), r = rfind(x);

	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			dp[i][j][0] = dp[i][j][1] = -1;
		}
	}

	printf("%lld\n", min(dy(l, l, 0) + abs(x-p[l]) * n, dy(r, r, 1) + abs(p[r]-x) * n));

}