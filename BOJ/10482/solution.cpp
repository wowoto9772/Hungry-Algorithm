#include <stdio.h>

bool p[32003] = { true, true, };
int a[32000][2];

int main(){
	for (int i = 2; i*i <= 32000; i++){
		if (!p[i]){
			for (int j = i*i; j <= 32000; j += i){
				p[j] = true;
			}
		}
	}

	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		int c = 0;
		for (int i = 2; i <= n / 2; i++){
			if (!p[i] && !p[n - i]){
				a[c][0] = i, a[c][1] = n - i;
				c++;
			}
		}

		printf("%d has %d representation(s)\n", n, c);
		for (int i = 0; i < c; i++)printf("%d+%d\n", a[i][0], a[i][1]);

		printf("\n");
	}
}