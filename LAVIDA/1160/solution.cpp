#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class ele{
public:
	int i, j, f;
	bool operator < (const ele &A)const{
		if (i == A.i){
			if (!f)return j < A.j;
			else
				return j > A.j;
		}
		return i < A.i;
	}
}X[101];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
			
		int m;
		scanf("%d", &m);

		int t1, t2, a, b;

		scanf("%d", &a);

		int top = 0;

		for (int i = 1; i <= a; i++){
			scanf("%d:%d", &t1, &t2);
			X[top].i = t1 * 60 + t2, X[top].j = 0, X[top].f = 0;
			top++;
		}

		scanf("%d", &b);
		for (int i = 1; i <= b; i++){
			scanf("%d:%d", &t1, &t2);
			X[top].i = t1 * 60 + t2, X[top].j = 1, X[top].f = 0;
			top++;
		}

		sort(X, X + top);

		bool chk[101] = { 0 };

		int c = 0;

		for (int i = 0; i < top; i++){
			if (!chk[i]){
				chk[i] = true;
				c++;
				int s = i;
				for (int j = i + 1; j < top; j++){
					if (!chk[j]){
						if (X[s].j != X[j].j){
							if (X[s].i + m <= X[j].i){
								chk[j] = true;
								s = j;
							}
						}
						else if (X[s].i + 2 * m <= X[j].i){
							chk[j] = true;
							s = j;
						}
					}
				}
			}
		}

		printf("%d\n", c);
	}
}

/*
50
15
07:30
07:40
07:50
08:40
09:10
14:50
15:20
16:00
16:20
16:40
17:00
18:00
18:40
18:50
18:50
9
11:50
12:40
13:40
14:30
15:20
15:50
19:50
20:20
20:20

4
*/

//#include <stdio.h>
//#include <memory.h>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//class ele{
//public:
//	int i, j;
//	bool operator < (const ele &A)const{
//		if (i == A.i)return j < A.j;
//		return i < A.i;
//	}
//}X[101];
//
//int cap[53][53];
//int flow[53][53];
//int P[53];
//
//int m(int a, int b){ return a < b ? a : b; }
//int max_flow(int source, int sink){
//	int ret = 0;
//	memset(flow, 0, sizeof(flow));
//
//	while (true){
//		queue <int> Q;
//		memset(P, 0xff, sizeof(P));
//
//		P[source] = source;
//		Q.push(source);
//
//		while (!Q.empty() && P[sink] == -1){
//			int now = Q.front(); Q.pop();
//			int k = 0;
//			for (int nxt = 0; nxt <= 41; nxt++){
//				if (cap[now][nxt] - flow[now][nxt] > 0 && P[nxt] == -1){
//					Q.push(nxt);
//					P[nxt] = now;
//					k++;
//				}
//			}
//		}
//
//		if (P[sink] == -1)break;
//
//		int amount = INT_MAX;
//
//		for (int p = sink; p != source; p = P[p])amount = m(amount, cap[P[p]][p] - flow[P[p]][p]);
//		for (int p = sink; p != source; p = P[p]){
//			flow[P[p]][p] += amount;
//			flow[p][P[p]] -= amount;
//		}
//
//		ret += amount;
//	}return ret;
//}
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//
//		int m;
//		scanf("%d", &m);
//
//		int t1, t2, a, b;
//
//		scanf("%d", &a);
//
//		int top = 1;
//
//		for (int i = 1; i <= a; i++){
//			scanf("%d:%d", &t1, &t2);
//			X[top].i = t1 * 60 + t2, X[top].j = 0;
//			top++;
//		}
//
//		scanf("%d", &b);
//		for (int i = 1; i <= b; i++){
//			scanf("%d:%d", &t1, &t2);
//			X[top].i = t1 * 60 + t2, X[top].j = 1;
//			top++;
//		}
//
//		sort(X+1, X + top);
//
//		memset(cap, 0, sizeof(cap));
//
//		for (int i = 1; i < top; i++){
//			cap[0][i] = 1;
//			bool f = false;
//			for (int j = i + 1; j < top; j++){
//				if (X[i].i + m <= X[j].i && X[i].j != X[j].j){
//					cap[i][j] = 1;
//					f = true;
//					cap[j][41] = 1;
//				}
//			}
//			if (!f)cap[i][41] = 1;
//			//cap[i][41] = 1;
//		}
//
//		printf("%d\n", max_flow(0, 41));
//	}
//}
