//#include <stdio.h>
//#include <string>
//#include <iostream>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//class partner{
//public:
//	string L, R;
//};
//
//map <string, bool> achk; // absolutely exist.
//vector <partner> comp[25]; // compose
//
//int ans = 0, k;
//int rans = 50;
//
//void srch(int cur, int cnt){
//	if (rans <= cnt)return ;
//
//	if (cur == k + 1){
//
//		if (rans > cnt){
//			rans = cnt;
//		}
//
//		return;
//	}
//	if (comp[cur].size() == 1){
//		srch(cur + 1, cnt);
//	}
//	else{
//		for (int i = 0; i < comp[cur].size(); i++){
//
//			if (rans <= cnt)return;
//
//			string L = comp[cur][i].L;
//			string R = comp[cur][i].R;
//
//			if (achk[L] && achk[R])srch(cur + 1, cnt);
//			else{
//				if (achk[L]){
//					achk[R] = true;
//					srch(cur + 1, cnt + 1);
//					achk[R] = false;
//				}
//				else if (achk[R]){
//					achk[L] = true;
//					srch(cur + 1, cnt + 1);
//					achk[L] = false;
//				}
//				else{
//					if (L != R){
//						achk[L] = true;
//						achk[R] = true;
//						srch(cur + 1, cnt + 2);
//						achk[L] = false;
//						achk[R] = false;
//					}
//					else{
//						achk[L] = true;
//						srch(cur + 1, cnt + 1);
//						achk[L] = false;
//					}
//				}
//			}
//		}
//	}
//}
//
//int main(){
//	int	n;
//	scanf("%d %d", &n, &k);
//
//	for (int i = 1; i <= k; i++){
//		char str[30] = { 0 };
//		scanf("%s", str);
//
//		string L, R;
//		string L2, R2;
//
//		int l = 0;
//		for (int j = 0; j < n; j++){
//			int a = str[j] - '0';
//			if (a == 0){
//				L += '0';
//				R += '0';
//				L2 += '0';
//				R2 += '0';
//			}
//			else if (a == 1){
//				if (l == 0){
//					L += '1';
//					R += '0';
//					l++;
//					L2 += '1';
//					R2 += '0';
//				}
//				else if (l == 1){
//					L += '0';
//					R += '1';
//					L2 += '1';
//					R2 += '0';
//				}
//			}
//			else if (a == 2){
//				L += '1';
//				R += '1';
//				L2 += '1';
//				R2 += '1';
//			}
//		}
//
//		partner psh = { L, R };
//		comp[i].push_back(psh);
//		psh = { L2, R2 };
//		comp[i].push_back(psh);
//	}
//
//	srch(1, 0);
//
//	printf("%d\n", rans);
//}

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class partner{
public:
	int L, R;
};

bool achk[500]; // absolutely exist.
vector <partner> comp[25]; // compose

int k;
int rans;

void srch(int cur, int cnt){ // O(2^24)
	if (rans <= cnt)return;

	if (cur == k + 1){

		if (rans > cnt){
			rans = cnt;
		}

		return;
	}
	if (comp[cur].size() == 1){
		srch(cur + 1, cnt);
	}
	else{
		for (int i = 0; i < comp[cur].size(); i++){

			if (rans <= cnt)return;

			int L = comp[cur][i].L;
			int R = comp[cur][i].R;

			if (achk[L] && achk[R])srch(cur + 1, cnt);
			else{
				if (achk[L]){
					achk[R] = true;
					srch(cur + 1, cnt + 1);
					achk[R] = false;
				}
				else if (achk[R]){
					achk[L] = true;
					srch(cur + 1, cnt + 1);
					achk[L] = false;
				}
				else{
					if (L != R){
						achk[L] = true;
						achk[R] = true;
						srch(cur + 1, cnt + 2);
						achk[L] = false;
						achk[R] = false;
					}
					else{
						achk[L] = true;
						srch(cur + 1, cnt + 1);
						achk[L] = false;
					}
				}
			}
		}
	}
}

int main(){
	int	n;
	scanf("%d %d", &n, &k);

	map <string, int> id;

	int idtop = 0;

	for (int i = 1; i <= k; i++){
		char str[30] = { 0 };
		scanf("%s", str);

		string L, R;
		string L2, R2;

		int l = 0, r;
		for (int j = 0; j < n; j++){
			int a = str[j] - '0';
			if (a == 0){
				L += '0';
				R += '0';
				L2 += '0';
				R2 += '0';
			}
			else if (a == 1){
				if (l == 0){
					L += '1';
					R += '0';
					l++;
					L2 += '1';
					R2 += '0';
				}
				else if (l == 1){
					L += '0';
					R += '1';
					L2 += '1';
					R2 += '0';
				}
			}
			else if (a == 2){
				L += '1';
				R += '1';
				L2 += '1';
				R2 += '1';
			}
		}

		if (id[L])l = id[L];
		else{
			id[L] = ++idtop;
			l = id[L];
		}
		if (id[R])r = id[R];
		else{
			id[R] = ++idtop;
			r = id[R];
		}
		partner psh = { l, r };
		comp[i].push_back(psh);

		if (id[L2])l = id[L2];
		else{
			id[L2] = ++idtop;
			l = id[L2];
		}
		if (id[R2])r = id[R2];
		else{
			id[R2] = ++idtop;
			r = id[R2];
		}
		psh = { l, r };
		comp[i].push_back(psh);
	}

	rans = n * 2;

	srch(1, 0);

	printf("%d\n", rans);
}