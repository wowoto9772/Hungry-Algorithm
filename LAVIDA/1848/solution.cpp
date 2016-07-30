#include <string.h>
#include <stdio.h>
#include <memory.h>

#define MAX 1000000007

int K, L;

int dp[95][95]; // i-th position start j
int nc[95][95];
int f[95];

char k[95], l[95];
int m(int a, int b){ return a < b ? a : b; }

int dy(int p, int c){
	if (p > K)return MAX;
	else if (p == K){
		if (c == L)return 0;
		else
			return MAX;
	}

	if (dp[p][c] != -1)return dp[p][c];

	dp[p][c] = MAX;

	int sum = 0;

	for (int i = c; i <= L; i++)sum += f[i] * (i - c + 1);

	for (int i = L; i >= c; i--){
		int x = sum + dy(p + 1, i + 1);
		if (dp[p][c] >= x){
			dp[p][c] = x;
			nc[p][c] = i+1;
		}
		sum -= f[i] * (i - c + 1);
	}

	return dp[p][c];
}

int main(){
	int t;
	scanf("%d", &t);

	for (int T = 1; T <= t; T++){
		memset(dp, 0xff, sizeof(dp));

		scanf("%d %d", &K, &L);
		if (T == 312){
			printf("");
		}
		scanf("%s %s", k, l);

		for (int i = 0; i < L; i++){

			scanf("%d", &f[i]);
		}

		dy(0, 0);

		printf("Keypad #%d:\n", T);

		int s = 0, c = 0;

		bool f = false;

		for (int i = 0; i < K; i++){
			printf("%c: ", k[i]);
			for (int j = s; !f && j < nc[i][c]; j++){
				if (j == L + 1)continue;
				printf("%c", l[j]);
			}printf("\n");
			s = nc[i][c];
			c = nc[i][c];
			if (c == L + 1)f = true;
		}
		printf("\n");
	}
}

/*

If there are more solutions with the same price, 
we will try to maximise the number of letters assigned 
to the last key, then to the one before the last one etc.

1
2 3
12
abc
1
1
1

답은
a
bc
이렇게 되야함

ab
c 가 아님.
*/