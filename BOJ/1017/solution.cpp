////#include <stdio.h>
////#include <limits.h>
////#include <memory.h>
////#include <queue>
////#include <algorithm>
////
////using namespace std;
////
////int flow[203][203];
////int cap[203][203];
////int p[203];
////
////int maximum_flow(int s, int e){
////	memset(flow, 0, sizeof(flow));
////
////	int ret = 0;
////	while (true){
////		memset(p, 0xff, sizeof(p));
////		queue <int> q;
////		q.push(s);
////
////		while (!q.empty() && p[e] == -1){
////			int c = q.front(); q.pop();
////			for (int i = 1; i <= e; i++){
////				if (cap[c][i] - flow[c][i] > 0 && p[i] == -1){
////					p[i] = c;
////					q.push(i);
////				}
////			}
////		}
////
////		if (p[e] == -1)return ret;
////
////		int f = e;
////		int cf = INT_MAX;
////		while (p[f] != -1){
////			cf = min(cf, cap[p[f]][f] - flow[p[f]][f]);
////			f = p[f];
////		}
////
////		f = e;
////		while (p[f] != -1){
////			flow[p[f]][f] += cf;
////			flow[f][p[f]] -= cf;
////			f = p[f];
////		}
////
////		ret += cf;
////	}
////}
////
////bool isP(int a){
////	if (!(a % 2))return false;
////	for (int i = 3; i*i <= a; i += 2){
////		if (a%i)continue;
////		else
////			return false;
////	}return true;
////}
////
////int main(){
////	int n;
////	scanf("%d", &n);
////
////	int I[53];
////	for (int i = 1; i <= n; i++){
////		scanf("%d", &I[i]);
////	}
////
////	int ans[53], top = 0;
////	for (int x = 2; x <= n; x++){
////		if (isP(I[1] + I[x])){
////			memset(cap, 0, sizeof(cap));
////			for (int i = 2; i <= n; i++){
////				if (i == x)continue;
////				cap[0][i] = 1;
////				for (int j = i+1; j <= n; j++){
////					if (j == x)continue;
////					if (isP(I[i] + I[j])){
////						cap[i][n + j] = 1;
////						cap[n + j][j] = 1;
////						cap[n + j][2 * n + 1] = 1;
////					}
////				}
////			}
////			int a = maximum_flow(0, 2*n + 1);
////			if (a >= (n-2)/2){
////				ans[top++] = I[x];
////			}
////		}
////	}
////
////	if (!top)printf("-1\n");
////	else{
////		sort(ans, ans + top);
////		for (int i = 0; i < top-1; i++){
////			printf("%d ", ans[i]);
////		}
////		printf("%d\n", ans[top - 1]);
////	}
////}
//
///*
//
//6
//6 1 12 4 7 10 11
//
//4
//1 12 10 11
//*/

#include <stdio.h>
#include <limits.h>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;

int aMatch[55], bMatch[55];
bool adj[55][55];
bool seen[55];

int n;

bool isP(int a){
	if (!(a % 2))return false;
	for (int i = 2; i*i <= a; i ++){
		if (a%i)continue;
		else
			return false;
	}return true;
}

bool dfs(int a){
	if (seen[a])return false;
	seen[a] = true;
	for (int b = 1; b <= n; b++){
		if (adj[a][b]){
			if (bMatch[b] == -1 || dfs(bMatch[b])){
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
		}
	}return false;
}

int main(){
	scanf("%d", &n);

	int I[53];
	for (int i = 1; i <= n; i++){
		scanf("%d", &I[i]);
	}

	int ans[53], top = 0;
	for (int x = 2; x <= n; x++){
		if (isP(I[1] + I[x])){
			memset(adj, 0, sizeof(adj));
			memset(aMatch, 0xff, sizeof(aMatch));
			memset(bMatch, 0xff, sizeof(bMatch));

			aMatch[1] = x;
			bMatch[x] = 1;

			int c = 0;
			for (int i = 2; i <= n; i++){
				if (x == i)continue;
				for (int j = 2; j <= n; j++){
					if (i == j || j == x)continue;
					if (isP(I[i] + I[j]))adj[i][j] = true;
				}
			}

			for (int s = 1; s <= n; s++){
				memset(seen, 0, sizeof(seen));
				if (dfs(s))c++;
			}

			if (c == (n - 2)){
				ans[top++] = I[x];
			}
		}
	}

	if (!top)printf("-1\n");
	else{
		sort(ans, ans + top);
		for (int i = 0; i < top - 1; i++){
			printf("%d ", ans[i]);
		}
		printf("%d\n", ans[top - 1]);
	}
}

//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<cstring>
//using namespace std;
//vector<int> path[100];
//int A, B, aMatch[100], bMatch[100];
//int n, a[100], id[100], lu[100], chk[100];
//bool isPrime(int x){
//	if (x == 1)return 0;
//	if (x == 2)return 1;
//	if (x % 2 == 0)return 0;
//	for (int i = 3; i*i <= x; i += 2){
//		if (x%i == 0)return 0;
//	}
//	return 1;
//}
//bool dfs(int a, int l){
//	if (chk[a])return 0;
//	chk[a] = 1;
//	for (int b : path[a]){
//		if (b == l)continue;
//		if (bMatch[b]<0 || dfs(bMatch[b], l)){
//			aMatch[a] = b;
//			bMatch[b] = a;
//			return 1;
//		}
//	}
//	return 0;
//}
//int main(){
//	ios::sync_with_stdio(0);
//	cin >> n;
//	for (int i = 0; i<n; i++)cin >> a[i];
//	for (int i = 0; i<n; i++){
//		if (abs(a[i] - a[0]) % 2 == 0){
//			id[i] = A++;
//		}
//		else{
//			id[i] = B++;
//			lu[B - 1] = a[i];
//		}
//	}
//	for (int i = 0; i<n; i++)
//		for (int j = i + 1; j<n; j++)
//			if (isPrime(a[i] + a[j])){
//				if ((a[i] - a[0]) % 2 == 0)path[id[i]].push_back(id[j]);
//				else path[id[j]].push_back(id[i]);
//			}
//
//	vector<int> ans;
//	for (int i : path[0]){
//		memset(aMatch, -1, sizeof(aMatch));
//		memset(bMatch, -1, sizeof(bMatch));
//		aMatch[0] = i;
//		bMatch[i] = 0;
//		int sum = 1;
//		for (int j = 1; j<A; j++){
//			memset(chk, 0, sizeof(chk));
//			if (dfs(j, i))sum++;
//		}
//		if (sum == n / 2){
//			ans.push_back(lu[i]);
//		}
//	}
//	sort(ans.begin(), ans.end());
//	if (ans.empty())cout << -1 << endl;
//	else for (int i : ans)cout << i << " ";
//}

//#include <stdio.h>
//#include <limits.h>
//#include <memory.h>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//int flow[203][203];
//int cap[203][203];
//int p[203];
//// 6 1 12 4 7 10 11
//int maximum_flow(int s, int e){
//	memset(flow, 0, sizeof(flow));
//
//	int ret = 0;
//	while (true){
//		memset(p, 0xff, sizeof(p));
//		queue <int> q;
//		q.push(s);
//
//		while (!q.empty() && p[e] == -1){
//			int c = q.front(); q.pop();
//			for (int i = 1; i <= e; i++){
//				if (cap[c][i] - flow[c][i] > 0 && p[i] == -1){
//					p[i] = c;
//					q.push(i);
//				}
//			}
//		}
//
//		if (p[e] == -1)return ret;
//
//		int f = e;
//		int cf = INT_MAX;
//		while (p[f] != -1){
//			cf = min(cf, cap[p[f]][f] - flow[p[f]][f]);
//			f = p[f];
//		}
//
//		f = e;
//		while (p[f] != -1){
//			flow[p[f]][f] += cf;
//			flow[f][p[f]] -= cf;
//			f = p[f];
//		}
//
//		ret += cf;
//	}
//}
//
//bool isP(int a){
//	if (!(a % 2))return false;
//	for (int i = 3; i*i <= a; i += 2){
//		if (a%i)continue;
//		else
//			return false;
//	}return true;
//}
//
//int main(){
//	int n;
//	scanf("%d", &n);
//
//	int I[53];
//	for (int i = 1; i <= n; i++){
//		scanf("%d", &I[i]);
//	}
//
//	int ans[53], top = 0;
//	for (int x = 2; x <= n; x++){
//		if (isP(I[1] + I[x])){
//			memset(cap, 0, sizeof(cap));
//			for (int i = 2; i <= n; i++){
//				if (i == x)continue;
//				for (int j = 2; j <= n; j++){
//					if (j == x || i == j)continue;
//					if (isP(I[i] + I[j])){
//						cap[i][j] = 1;
//					}  
//				}
//			}
//			int a = maximum_flow(0, n + 1);
//			if (a >= (n-2)/2){
//				ans[top++] = I[x];
//			}
//		}
//	}
//
//	if (!top)printf("-1\n");
//	else{
//		sort(ans, ans + top);
//		for (int i = 0; i < top-1; i++){
//			printf("%d ", ans[i]);
//		}
//		printf("%d\n", ans[top - 1]);
//	}
//}
