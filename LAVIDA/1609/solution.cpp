// Math : mapping

#include <stdio.h>
#include <queue>
#define MAX 10

using namespace std;

int main()
{/*

	// BOT  : 0
	// T    : 1
	// R    : 2
	// L    : 3
	// F    : 4
	// BACK : 5

	int d[6][2] = { 0 };
	// [][0] : R 
	// [][1] : T
	d[0][0] = 3, d[0][1] = 4;
	d[1][0] = 2, d[1][1] = 5;
	d[2][0] = 0, d[2][1] = 2;
	d[3][0] = 1, d[3][1] = 3;
	d[4][0] = 4, d[4][1] = 1;
	d[5][0] = 5, d[5][1] = 0;

	queue <int> r, c, a;
	r.push(0), c.push(0), a.push(1);
	int cnt[MAX+1][MAX+1] = { 0 };
	while (!r.empty()){
		// right
		int R = r.front(), C = c.front(), A = a.front();
		r.pop(), c.pop(), a.pop();
		// top
		int N = d[A][0];
		if (C + 1 <= MAX){
			if (N == 1){
				cnt[R][C + 1]++;
			}
			else{
				r.push(R), c.push(C + 1), a.push(N);
			}
		}
		N = d[A][1];
		if (R + 1 <= MAX){
			if (N == 1){
				cnt[R + 1][C]++;
			}
			else{
				r.push(R+1), c.push(C), a.push(N);
			}
		}
	}

	for (int i = MAX; i >= 1; i--){
		for (int j = 1; j <= MAX; j++){
			printf("%2d ", cnt[i][j]);
		}printf("\n");
	}*/

	int t;
	scanf("%d", &t);

	while (t--){
		int a, b;
		scanf("%d %d", &a, &b);

		if (a > b){
			int k = a;
			a = b;
			b = k;
		}

		int ans;

		if (a == 1){
			if (b == 4)ans = 2;
			else
				ans = 0;
		}
		else if (a == b){
			if (a == 4)ans = 12;
			else
				ans = 2;
		}
		else{
			if (a == 4)ans = b + 3;
			else if (a == 2){
				if (b == 4)ans = 5;
				else
					ans = 2;
			}
			else if (a == 3){
				if (b == 4)ans = 6;
				else
					ans = 2;
			}
			else
				ans = 2;
		}

		printf("%d\n", ans);
	}
}

/*

주사위에서 1을 기준으로 봄
R    T
T    R    BACK
BOT  L    F
L    F    L
R    BACK R
F    F    T
BACK BACK BOT
*/