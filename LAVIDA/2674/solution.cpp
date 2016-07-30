#include <stdio.h>

long long v[4003], d[4003], p[4003];
int ans[4003];

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%lld %lld %lld", &v[i], &d[i], &p[i]);
	}

	for (int i = 1; i <= n; i++){
		if (p[i] >= 0){
			ans[0]++;
			ans[ans[0]] = i;

			d[0] = 0;
			for (int j = i + 1; j <= n; j++){
				if (p[j] >= 0){
					if (v[i])p[j] -= v[i]--;
					p[j] -= d[0];
					if (p[j] < 0){
						d[0] += d[j];
					}
				}
			}
		}
	}

	printf("%d\n", ans[0]);
	for (int i = 1; i <= ans[0]; i++){
		printf("%d", ans[i]);
		if (i < ans[0])printf(" ");
	}printf("\n");
}