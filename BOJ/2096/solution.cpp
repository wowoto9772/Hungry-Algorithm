#include <stdio.h>
#include <memory.h>

#define max 1000000007

int I[100003][3];
int M(int a, int b){ return a < b ? b : a; }
int m(int a, int b){ return a < b ? a : b; }
int main(){
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)for (int j = 0; j <= 2; j++)scanf("%d", &I[i][j]);

	int a = I[1][0], b = I[1][1], c = I[1][2];
	int a_, b_, c_;

	for (int i = 2; i <= n; i++){
		a_ = I[i][0] + M(a, b);
		b_ = I[i][1] + M(a, M(b, c));
		c_ = I[i][2] + M(b, c);
		a = a_;
		b = b_;
		c = c_;
	}

	printf("%d ", M(a, M(b, c)));

	a = I[1][0], b = I[1][1], c = I[1][2];
	for (int i = 2; i <= n; i++){
		a_ = I[i][0] + m(a, b);
		b_ = I[i][1] + m(a, m(b, c));
		c_ = I[i][2] + m(b, c);
		a = a_;
		b = b_;
		c = c_;
	}

	printf("%d\n", m(a, m(b, c)));
}