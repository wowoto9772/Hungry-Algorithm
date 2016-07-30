#include <stdio.h>

int b[100003];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++){
		scanf("%d", &b[i]);
	}

	int l = 1, r = 1000000000, m;

	while (l <= r){
		m = (l + r) / 2;

		int w = 0, c = 1;
		for (int i = 1; i <= n; i++){
			if (w + b[i] <= m){
				w += b[i];
			}
			else{
				c++;
				w = b[i];
			}
		}

		if (c > k){
			l = m + 1;
		}
		else
			r = m - 1;
	}

	int w = 0, c = 1;
	for (int i = 1; i <= n; i++){
		if (w + b[i] <= m){
			w += b[i];
		}
		else{
			c++;
			w = b[i];
		}
	}

	if (c > k){
		m++;
	}

	printf("%d\n", m);
}