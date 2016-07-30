#include <stdio.h>

bool p[503];
int P[103];
int top;

int main()
{
	int nxt;
	for (int i = 2; i*i <= 500; i++){
		nxt = i;
		if (!p[i]){
			P[top++] = i;
			for (int j = i + i; j <= 500; j += i)p[j] = true;
		}
	}for (int i = nxt + 1; i <= 500; i++)if (!p[i])P[top++] = i;

	int n;

	while (scanf("%d", &n) == 1){
		int A[103] = { 0 };
		for (int i = 0; P[i] <= n && i < top; i++){
			int k = 1;
			for (int j = 1; k <= n; j++){
				k *= P[i];
				A[i] += n / k;
			}
		}

		int ans = A[0] < A[2] ? A[0] : A[2];

		printf("%d\n", ans);
	}
}