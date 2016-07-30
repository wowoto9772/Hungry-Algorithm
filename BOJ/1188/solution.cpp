#include <stdio.h>

int gcd(int a, int b){
	int m = 1;
	while (m){
		m = a % b;
		a = b;
		b = m;
	}return a;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	int g = gcd(n, m);
	int n_ = n / g, m_ = m / g;

	int ans = 0;
	int rem = 0;
	for (int i = 1; i <= n; i++){
		int son = m_;
		while (son){
			if (rem + son > n_){
				ans++;
				int minus = n_ - rem;
				son -= minus;
				rem = 0;
			}
			else{
				rem += son;
				rem %= n_;
				son = 0;
			}
		}
	}

	printf("%d\n", ans);
}