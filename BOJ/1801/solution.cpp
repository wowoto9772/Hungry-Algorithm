//#include <stdio.h>
//
//#include <algorithm>
//#include <map>
//#include <vector>
//
//using namespace std;
//
//int n;
//int l[16];
//int d[4][4] = { { 1, 0, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 1 } };
//
//map <vector <int>, int> dp;
//
//vector <int> nlen(4);
//
//int dy(int c, vector <int> len){
//
//	if (dp[len])return dp[len];
//
//	if (len[0] == len[1] && len[2] == len[3])dp[len] = len[0] * len[2];
//	else
//		dp[len] = 0;
//
//	if (c < n){
//		for (int i = 0; i < 4; i++){
//			bool flag = false;
//			for (int j = 0; j < 4; j++){
//				nlen[j] = len[j] + l[c] * d[i][j];
//				if (nlen[j] >= 80){
//					flag = true;
//					break;
//				}
//			}
//			if (!flag){
//				sort(nlen.begin(), nlen.end());
//				dp[len] = max(dp[len], dy(c + 1, nlen));
//			}
//		}
//
//		dp[len] = max(dp[len], dy(c + 1, len));
//	}
//
//	if (!dp[len])dp[len] = -1;
//
//	return dp[len];
//
//}
//
//int main(){
//
//
//	scanf("%d", &n);
//	
//	for (int i = 0; i < n; i++){
//		scanf("%d", &l[i]);
//	}
//
//	sort(l, l + n);
//
//	int flg = dy(0, nlen);
//	printf("%d\n", flg > 0 ? flg : -1);
//
//}

//#include <stdio.h>
//
//#include <algorithm>
//#include <map>
//#include <vector>
//
//using namespace std;
//
//int n;
//int l[16];
//int d[4][4] = { { 1, 0, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 1 } };
//
//map <vector <int>, int> dp;
//
//vector <int> nlen(4);
//
//int dy(int c, vector <int> len){
//
//	if (dp[len])return dp[len];
//
//	if (len[0] && len[0] == len[1] && len[2] == len[3])dp[len] = len[0] * len[2];
//	else
//		dp[len] = -1;
//
//	if (c < n){ 
//		for (int i = 0; i < 4; i++){
//			bool flag = false;
//			for (int j = 0; j < 4; j++){
//				nlen[j] = len[j] + l[c] * d[i][j];
//				if (nlen[j] >= 80){
//					flag = true;
//					break;
//				}
//			}
//			if (!flag){
//				sort(nlen.begin(), nlen.end());
//				dp[len] = max(dp[len], dy(c + 1, nlen));
//			}
//			else
//				break;
//		}
//
//		dp[len] = max(dp[len], dy(c + 1, len));
//	}
//
//	return dp[len];
//
//}
//
//int main(){
//
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++){
//		scanf("%d", &l[i]);
//	}
//
//	sort(l, l + n);
//
//	printf("%d\n", dy(0, nlen));
//
//}
//

#include <stdio.h>

#include <algorithm>

using namespace std;

int n;

int l[16];
int L[1 << 16];
bool dp[1 << 16];
bool pos[163];

int ans = -1;

void Rectangle(int c, int W, int H){

	if (dp[W] & dp[H]){
		ans = max(ans, (L[W] / 2) * (L[H]) / 2);
	}

	if (c < n){
		Rectangle(c + 1, W | (1 << c), H);
		Rectangle(c + 1, W, H | (1 << c));
		Rectangle(c + 1, W, H);
	}

}

int main(){

	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%d", &l[i]);
	}

	sort(l, l + n);

	pos[0] = true;

	for (int i = 1; i < (1 << n); i++){

		for (int j = 0; j < n; j++){
			L[i] += ((1 << j)&i) ? l[j] : 0;
		}

		if (L[i] % 2)continue;

		for (int j = 1; j <= L[i] / 2; j++)pos[j] = false;

		for (int j = 0; j < n; j++){
			if ((1 << j)&i){
				for (int k = L[i] / 2; k - l[j] >= 0; k--){
					if (pos[k - l[j]])pos[k] = true;
				}
			}
		}
		if (pos[L[i] / 2])dp[i] = true;
	}

	Rectangle(0, 0, 0);

	printf("%d\n", ans);

}