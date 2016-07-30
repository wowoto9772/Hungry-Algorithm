#include <stdio.h>

int a[100003];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n, S;
		scanf("%d %d", &n, &S);
		for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
		int f = 1;
		int min = n + 1;
		int s = 0;
		for (int i = 1; i <= n; i++){
			s += a[i];
			while (s >= S){
				if (min > i - f + 1){
					min = i - f + 1;
				}
				s -= a[f];
				f++;
			}
		}

		if (min == n + 1)min = 0;

		printf("%d\n", min);
	}
}
