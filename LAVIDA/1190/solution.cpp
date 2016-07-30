////#include <stdio.h>
////#include <vector>
////
////using namespace std;
////
////int dfn[2000003];
////int colour[2000003];
////int top;
////
////vector <int> lnk[2000003];
////vector <int> ans;
////int m(int a, int b){ return a < b ? a : b; }
////
////int dfs(int u, int p){
////	colour[u] = 1;
////	dfn[u] = top++;
////	int leastAncestor = top;
////
////	for (int i = 0; i < lnk[u].size(); i++){
////		int v = lnk[u][i];
////		if (v != p){
////			if (colour[v] == 0){
////				// (u, v) is a forward edge
////				int rec = dfs(v, u);
////				if (rec > dfn[u]){
////					// bcc count
////					ans.push_back(p);
////				}
////				leastAncestor = m(leastAncestor, rec);
////			}
////			else{
////				/// (u, v) is a back edge
////				leastAncestor = m(leastAncestor, dfn[v]);
////			}
////		}
////	}
////	colour[u] = 2;
////	return leastAncestor;
////}
////
////int main(){
////	int n;
////	scanf("%d", &n);
////
////	for (int i = 1; i <= n; i++){
////		int a, b;
////		scanf("%d %d", &a, &b);
////
////		lnk[a].push_back(b);
////		lnk[b].push_back(a);
////	}
////
////	dfs(1, -1);
////
////	for (int i = 0; i < ans.size() - 1; i++)printf("%d ", ans[i]);
////	printf("%d\n", ans[ans.size() - 1]);
////}
////
/////*
////	bridge 찾기
////*/
//
//#include <stdio.h>
//#include <vector>
//
//using namespace std;
//
//int dfn[2000003];
//int colour[2000003];
//int top;
//
//vector <int> lnk[2000003];
//vector <int> ans;
//int m(int a, int b){ return a < b ? a : b; }
//
//int dfs(int u, int p){
//	colour[u] = 1;
//	dfn[u] = top++;
//	int leastAncestor = top;
//
//	for (int i = 0; i < lnk[u].size(); i++){
//		int v = lnk[u][i];
//		if (v != p){
//			if (colour[v] == 0){
//				// (u, v) is a forward edge
//				int rec = dfs(v, u);
//				if (rec > dfn[u]){
//					// bcc count
//					printf("%d %d\n", v, u);
//				}
//				leastAncestor = m(leastAncestor, rec);
//			}
//			else{
//				/// (u, v) is a back edge
//				leastAncestor = m(leastAncestor, dfn[v]);
//			}
//		}
//	}
//	colour[u] = 2;
//
//	return leastAncestor;
//}
//
//int main(){
//	int n;
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++)
//		int a, b;
//		scanf("%d %d", &a, &b);
//
//		lnk[a].push_back(b);
//		lnk[b].push_back(a);
//	}
//
//	dfs(1, -1);
//
//	for (int i = 0; i < ans.size() - 1; i++)printf("%d ", ans[i]);
//	//printf("%d\n", ans[ans.size() - 1]);
//}
//
///*
//	bridge 찾기
//	*/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<int> a[2000001];
bool c[10001];
int low[10001];
int num[10001];
int parent[10001];
int cnt = 0;
bool cut[10001];

void dfs(int x) {
	c[x] = true;
	num[x] = ++cnt;
	low[x] = cnt;
	int children = 0;
	for (int i = 0; i<a[x].size(); i++) {
		int y = a[x][i];
		if (c[y] == false) {
			children += 1;
			parent[y] = x;
			dfs(y);
			low[x] = min(low[x], low[y]);
			if (parent[x] == 0 && children >= 2) {
				cut[x] = true;
			}
			if (parent[x] != 0 && low[y] >= num[x]) {
				cut[x] = true;
			}
		}
		else if (y != parent[x]) {
			low[x] = min(low[x], num[y]);
		}
	}
}
int main() {
	int n, m;
	scanf("%d", &m);
	n = m - 1;

	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		//sort(a[i].begin(), a[i].end());
	}
	for (int i = 1; i <= n; i++) {
		if (c[i] == false) {
			dfs(i);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (cut[i]) {
			ans += 1;
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) {
		if (cut[i]) {
			printf("%d ", i);
		}
	}
	puts("");
	return 0;
}
