#include <cstdio>

using namespace std;

int x[103], y[103];

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%d %d", &x[i], &y[i]);

	int p = (1 << 31) - 1, q, r;

	for (int a = 1; a <= 100; a++){
		for (int b = 1; b <= 100; b++){
			int c = 0;
			for (int k = 0; k < n; k++){
				int d = (y[k] - (a*x[k] + b));
				c += d*d;
			}
			if (p > c){
				p = c;
				q = a, r = b;
			}
		}
	}

	printf("%d %d\n", q, r);

}