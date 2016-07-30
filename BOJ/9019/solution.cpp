//#include <stdio.h>
//#include <vector>
//#include <math.h>
//#include <queue>
//
//using namespace std;
//
//int size(int a){
//	if (!a)return 1;
//	int ret = 0;
//	while (a){
//		ret++;
//		a /= 10;
//	}return ret;
//}
//
//int op[10003];
//int rev[10003];
//int ten[] = { 1, 10, 100, 1000, 10000 };
//
//int main(){
//
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//
//		int s, a;
//		scanf("%d %d", &s, &a);
//
//		queue <int> q;
//		q.push(s);
//
//		for (int i = 0; i <= 10000; i++)rev[i] = -1;
//		rev[s] = 10001;
//
//		while (!q.empty() && rev[a] == -1){
//
//			int f = q.front(); q.pop();
//
//			// D
//			int m = (f * 2) % 10000;
//			if (rev[m] == -1){
//				op[m] = 'D';
//				rev[m] = f;
//				q.push(m);
//			}
//			// S
//			m = f - 1;
//			if (m == -1)m = 9999;
//			if (rev[m] == -1){
//				op[m] = 'S';
//				rev[m] = f;
//				q.push(m);
//			}
//			// L
//			m = ((f * 10)) % ten[size(f)];
//			m += f / ten[size(f) - 1];
//			if (rev[m] == -1){
//				op[m] = 'L';
//				rev[m] = f;
//				q.push(m);
//			}
//			// R
//			m = (f % 10) * ten[size(f) - 1] + f / 10;
//			if (rev[m] == -1){
//				op[m] = 'R';
//				rev[m] = f;
//				q.push(m);
//			}
//		}
//
//		vector <char> ans;
//
//		int src = a;
//		while (rev[src] != 10001){
//			ans.push_back(op[src]);
//			src = rev[src];
//		}
//
//		for (int i = ans.size() - 1; i >= 0; i--)printf("%c", ans[i]);
//		printf("\n");
//
//	}
//
//}

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int op[10003];
int rev[10003];

int main(){

	int t;
	scanf("%d", &t);

	while (t--){

		int s, a;
		scanf("%d %d", &s, &a);

		queue <int> q;
		q.push(s);

		for (int i = 0; i <= 10000; i++)rev[i] = -1;
		rev[s] = 10001;

		while (!q.empty() && rev[a] == -1){

			int f = q.front(); q.pop();

			// D
			int m = (f * 2) % 10000;
			if (rev[m] == -1){
				op[m] = 'D';
				rev[m] = f;
				q.push(m);
			}
			// S
			m = f - 1;
			if (m == -1)m = 9999;
			if (rev[m] == -1){
				op[m] = 'S';
				rev[m] = f;
				q.push(m);
			}
			// L
			m = (f * 10) % 10000 + f / 1000;
			if (rev[m] == -1){
				op[m] = 'L';
				rev[m] = f;
				q.push(m);
			}
			// R
			m = f % 10 * 1000 + f / 10;
			if (rev[m] == -1){
				op[m] = 'R';
				rev[m] = f;
				q.push(m);
			}
		}

		vector <char> ans;

		int src = a;
		while (rev[src] != 10001){
			ans.push_back(op[src]);
			src = rev[src];
		}

		for (int i = ans.size() - 1; i >= 0; i--)printf("%c", ans[i]);
		printf("\n");

	}

} 

// 1 =(L)> 10
// 21 =(R)> 2
