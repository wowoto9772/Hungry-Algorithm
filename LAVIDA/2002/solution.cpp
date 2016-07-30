//#include <stdio.h>
//#include <memory.h>
//#include <limits.h>
//
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//class ele{
//public:
//	int a, c;
//};
//
//int x[5003][2], y[5003][2];
//void swp(int *a, int *b){
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//int m(int a, int b){ return a < b ? a : b; }
//
//int main()
//{
//	int r, c;
//	scanf("%d %d", &r, &c);
//
//	int n;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++){
//		int trs;
//		scanf("%d", &trs);
//		for (int j = 0; j < 2; j++)scanf("%d %d", &x[i][j], &y[i][j]);
//		if (x[i][0] > x[i][1])swp(&x[i][0], &x[i][1]);
//		if (y[i][0] > y[i][1])swp(&y[i][0], &y[i][1]);
//	}
//
//	vector < vector <int> > L;
//	L.resize(n + 1);
//
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++){
//			if (i == j)continue;
//			if (x[i][0] == x[i][1]){ // 세로
//				if (y[j][0] == y[j][1]){ // 가로
//					if (x[j][0] <= x[i][0] && x[i][0] <= x[j][1]){
//						if (y[i][0] <= y[j][0] && y[j][0] <= y[i][1]){
//							L[i].push_back(j);
//						}
//					}
//				}
//				else{ // 세로
//					if (x[i][0] == x[j][0]){
//						if (y[i][0] <= y[j][1] && y[j][1] <= y[i][1]){
//							L[i].push_back(j);
//						}
//						else if (y[j][0] <= y[i][1] && y[i][1] <= y[j][1]){
//							L[i].push_back(j);
//						}
//					}
//				}
//			}
//			else{ // 가로
//				if (x[j][0] == x[j][1]){ // 세로
//					if (y[j][0] <= y[i][0] && y[i][0] <= y[j][1]){
//						if (x[i][0] <= x[j][0] && x[j][0] <= x[i][1]){
//							L[i].push_back(j);
//						}
//					}
//				}
//				else{ // 가로
//					if (y[i][0] == y[j][0]){
//						if (x[i][0] <= x[j][0] && x[j][0] <= x[i][1]){
//							L[i].push_back(j);
//						}
//						else if (x[j][0] <= x[i][1] && x[i][1] <= x[j][1]){
//							L[i].push_back(j);
//						}
//					}
//				}
//			}
//		}
//	}
//
//	int sx, sy, ax, ay;
//	scanf("%d %d %d %d", &sx, &sy, &ax, &ay);
//
//	ele psh, pop;
//
//	int ans = INT_MAX;
//
//	for (int i = 1; i <= n; i++){
//		if (x[i][0] <= sx && sx <= x[i][1]){
//			if (y[i][0] <= sy && sy <= y[i][1]){
//				queue <ele> Q;
//				int d[5003];
//				memset(d, 0x2f, sizeof(d));
//				psh.a = i, psh.c = 0;
//				Q.push(psh);
//				d[i] = 0;
//
//				while (!Q.empty()){
//					pop = Q.front(); Q.pop();
//					pop.c++;
//
//					for (int i = 0; i < L[pop.a].size(); i++){
//						int nxt = L[pop.a][i];
//						if (d[nxt] > pop.c){
//							d[nxt] = pop.c;
//							psh.a = nxt, psh.c = d[nxt];
//							Q.push(psh);
//						}
//					}
//				}
//
//				for (int j = 1; j <= n; j++){
//					if (x[j][0] <= ax && ax <= x[j][1]){
//						if (y[j][0] <= ay && ay <= y[j][1]){
//							ans = m(ans, d[j]);
//						}
//					}
//				}
//			}
//		}
//	}
//
//	printf("%d\n" , ans+1);
//}

/*
#include <stdio.h>
#include <memory.h>
#include <limits.h>

#include <vector>
#include <queue>

using namespace std;

class ele{
public:
int a, c;
};

int x[5003][2], y[5003][2];
bool L[5003][5003];
void swp(int *a, int *b){
int t = *a;
*a = *b;
*b = t;
}

int CCW(int x, int y, int x2, int y2, int x3, int y3){
long long k = (long long)x*y2 + x2*y3 + x3*y - x2*y - x3*y2 - x*y3;
if (k < 0)return -1;
else if (k > 0)return 1;
else
return 0;
}

int main()
{
int r, c;
scanf("%d %d", &r, &c);

int n;
scanf("%d", &n);
for (int i = 1; i <= n; i++){
int trs;
scanf("%d", &trs);
for (int j = 0; j < 2; j++)scanf("%d %d", &x[i][j], &y[i][j]);
if (x[i][0] > x[i][1])swp(&x[i][0], &x[i][1]);
if (y[i][0] > y[i][1])swp(&y[i][0], &y[i][1]);
}

for (int i = 1; i <= n; i++){
for (int j = i + 1; j <= n; j++){
if (x[i][0] == x[i][1]){ // 세로
if (y[j][0] == y[j][1]){ // 가로
if (x[j][0] <= x[i][0] && x[i][0] <= x[j][1]){
if (y[i][0] <= y[j][0] && y[j][0] <= y[i][1]){
L[i][j] = true;
L[j][i] = true;
}
}
}
else{ // 세로
if (x[i][0] == x[j][0]){
if (y[i][0] <= y[j][1] && y[j][1] <= y[i][1]){
L[i][j] = true;
L[j][i] = true;
}
else if (y[j][0] <= y[i][1] && y[i][1] <= y[j][1]){
L[i][j] = true;
L[j][i] = true;
}
}
}
}
else{ // 가로
if (x[j][0] == x[j][1]){ // 세로
if (y[j][0] <= y[i][0] && y[i][0] <= y[j][1]){
if (x[i][0] <= x[j][0] && x[j][0] <= x[i][1]){
L[i][j] = true;
L[j][i] = true;
}
}
}
else{ // 가로
if (y[i][0] == y[j][0]){
if (x[i][0] <= x[j][0] && x[j][0] <= x[i][1]){
L[i][j] = true;
L[j][i] = true;
}
else if (x[j][0] <= x[i][1] && x[i][1] <= x[j][1]){
L[i][j] = true;
L[j][i] = true;
}
}
}
}

}
}

int sx, sy, ax, ay;
scanf("%d %d %d %d", &sx, &sy, &ax, &ay);

ele psh, pop;

bool chk[5003] = { 0 };

queue <ele> Q;
for (int i = 1; i <= n; i++){
if (x[i][0] <= sx && sx <= x[i][1]){
if (y[i][0] <= sy && sy <= y[i][1]){
psh.a = i, psh.c = 1;
Q.push(psh);
chk[i] = true;
}
}
}

while (!Q.empty()){
pop = Q.front(); Q.pop();

if (x[pop.a][0] <= ax && ax <= x[pop.a][1]){
if (y[pop.a][0] <= ay && ay <= y[pop.a][1]){
printf("%d\n", pop.c);
break;
}
}

for (int j = 1; j <= n; j++){
if (L[pop.a][j] && !chk[j]){
chk[j] = true;
psh.a = j, psh.c = pop.c + 1;
Q.push(psh);
}
}
}
}

*/

#include <stdio.h>
#include <memory.h>
#include <limits.h>

#include <vector>
#include <queue>

using namespace std;

class ele{
public:
	int a, c;
};

int x[5003][2], y[5003][2];
bool L[5003][5003];
void swp(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int CCW(int x, int y, int x2, int y2, int x3, int y3){
	long long k = (long long)x*y2 + x2*y3 + x3*y - x2*y - x3*y2 - x*y3;
	if (k < 0)return -1;
	else if (k > 0)return 1;
	else
		return 0;
}

int main()
{
	int r, c;
	scanf("%d %d", &r, &c);

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		int trs;
		scanf("%d", &trs);
		for (int j = 0; j < 2; j++)scanf("%d %d", &x[i][j], &y[i][j]);
		if (x[i][0] > x[i][1])swp(&x[i][0], &x[i][1]);
		if (y[i][0] > y[i][1])swp(&y[i][0], &y[i][1]);
	}

	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			if (x[i][0] == x[i][1]){ // 세로
				if (y[j][0] == y[j][1]){ // 가로
					if (x[j][0] <= x[i][0] && x[i][0] <= x[j][1]){
						if (y[i][0] <= y[j][0] && y[j][0] <= y[i][1]){
							L[i][j] = true;
							L[j][i] = true;
						}
					}
				}
				else{ // 세로
					if (x[i][0] == x[j][0]){
						if (y[i][0] <= y[j][1] && y[j][1] <= y[i][1]){
							L[i][j] = true;
							L[j][i] = true;
						}
						else if (y[j][0] <= y[i][1] && y[i][1] <= y[j][1]){
							L[i][j] = true;
							L[j][i] = true;
						}
					}
				}
			}
			else{ // 가로
				if (x[j][0] == x[j][1]){ // 세로
					if (y[j][0] <= y[i][0] && y[i][0] <= y[j][1]){
						if (x[i][0] <= x[j][0] && x[j][0] <= x[i][1]){
							L[i][j] = true;
							L[j][i] = true;
						}
					}
				}
				else{ // 가로
					if (y[i][0] == y[j][0]){
						if (x[i][0] <= x[j][0] && x[j][0] <= x[i][1]){
							L[i][j] = true;
							L[j][i] = true;
						}
						else if (x[j][0] <= x[i][1] && x[i][1] <= x[j][1]){
							L[i][j] = true;
							L[j][i] = true;
						}
					}
				}
			}

		}
	}

	int sx, sy, ax, ay;
	scanf("%d %d %d %d", &sx, &sy, &ax, &ay);

	ele psh, pop;

	bool chk[5003] = { 0 };

	queue <ele> Q;
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j < n; j++){
			if (x[i][0] <= sx && sx <= x[i][1]){
				if (y[i][0] <= sy && sy <= y[i][1]){
					int a = CCW(x[i][0], y[i][0], x[i][1], y[i][1], x[j][0], y[j][0]);
					int b = CCW(x[i][0], y[i][0], x[i][1], y[i][1], x[j][1], y[j][1]);
					int c = CCW(x[j][0], y[j][0], x[j][1], y[j][1], x[i][0], y[i][0]);
					int d = CCW(x[j][0], y[j][0], x[j][1], y[j][1], x[i][1], y[i][1]);
					if (a * b <= 0){
						if (c * d <= 0){
							L[i][j] = true;
							L[j][i] = true;
						}
					}
				}
			}
		}

		while (!Q.empty()){
			pop = Q.front(); Q.pop();

			if (x[pop.a][0] <= ax && ax <= x[pop.a][1]){
				if (y[pop.a][0] <= ay && ay <= y[pop.a][1]){
					printf("%d\n", pop.c);
					break;
				}
			}

			for (int j = 1; j <= n; j++){
				if (L[pop.a][j] && !chk[j]){
					chk[j] = true;
					psh.a = j, psh.c = pop.c + 1;
					Q.push(psh);
				}
			}
		}
	}
}
	/*
	1 1
	4
	1 1 1 1 2
	1 2 1 1 1
	3 3 3 3 3
	1 1 2 1 5
	1 1 2 1

	*/