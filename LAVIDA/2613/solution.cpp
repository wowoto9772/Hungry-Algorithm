//#include <stdio.h>
//#include <memory.h>
//#include <queue>
//
//using namespace std;
//
//int chk[1000003];
//int I[1000003];
//
//int main()
//{
//	int n;
//	while (scanf("%d", &n) == 1 && n){
//
//		for (int i = 1; i <= n; i++)scanf("%d", &I[i]);
//		queue <int> q, x;
//		q.push(1), x.push(0);
//		chk[1] = 0;
//
//		while (!q.empty() && !chk[n]){
//			int f = q.front(), m = x.front(); q.pop(), x.pop();
//			int max = f + I[f];
//			if (f + I[f] >= n)max = n;
//			m++;
//			for (int i = max; !chk[n] && i >= f + 1; i--){
//				if (chk[i])continue;
//				chk[i] = m;
//				q.push(i); x.push(m);
//			}
//		}
//
//		printf("%d\n", chk[n]);
//
//		memset(chk, 0, sizeof(chk));
//	}
//}

#include <stdio.h>
#include <memory.h>

int chk[1000003];
int jump[1000003];

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n){

		for (int i = 1; i <= n; i++)scanf("%d", &jump[i]);
		
		int c = 0, go = 1;
		int curmax = 1 + jump[1];
		int ans = 0;
		int s = 2;
		while (!chk[n]){
			ans++;
			int nxtmax = curmax;
			int nxts;
			bool flag = false;
			for (int i = s; i <= curmax && i <= n; i++){
				flag = true;
				chk[i] = ans;
				if (nxtmax < i + jump[i]){
					nxtmax = i + jump[i];
				}
			}
			if (!flag){
				break;
			}
			s = curmax > n ? n : curmax;
			curmax = nxtmax;
		}

		printf("%d\n", chk[n]);

		memset(chk, 0, sizeof(chk));
	}
}