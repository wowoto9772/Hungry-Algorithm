#include <stdio.h>

int a[20];

int main(){
	int n, s;
	scanf("%d %d", &n, &s);

	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	int ans = 0;
	for (int i = 1; i < (1 << n); i++){
		int c = 0;
		for (int j = 0; j < n; j++){
			if (i&(1 << j))c += a[j];
		}
		if (c == s)ans++;
	}

	printf("%d\n", ans);
}