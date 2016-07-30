#include <stdio.h>
#include <memory.h>

bool p[1000003];
int P[100003];
int A[100003];
int top;

int main()
{
	int nxt;
	for (int i = 2; i*i < 1000000; i++){
		nxt = i;
		if (!p[i]){
			P[top++] = i;
			for (int j = i + i; j <= 1000000; j += i)p[j] = true;
		}
	}for (int i = nxt + 1; i <= 1000000; i++)if (!p[i])P[top++] = i;

	int n;

	while (scanf("%d", &n) == 1){
		memset(A, 0, sizeof(A));

		for (int i = 0; P[i] <= n && i < top; i++){
			int k = 1;
			for (int j = 1; k <= n; j++){
				k *= P[i];
				A[i] += n / k;
			}
		}

		int ans = A[0] < A[2] ? A[0] : A[2];
		A[0] -= ans;
		A[2] -= ans;

		long long m = 1;

		for (int i = 0; i < top && P[i] <= n; i++){
			if (A[i]){
				for (int j = 1; j <= A[i]; j++){
					m *= P[i];
					m %= 100000;
				}
			}
		}

		printf("%lld\n", m);
	}
}