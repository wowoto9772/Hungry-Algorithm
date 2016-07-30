#include <stdio.h>

int max(int a, int b){ return a > b ? a : b; }

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int l, n;
		scanf("%d %d", &l, &n);

		int ans = 0;
		for (int i = 1; i <= n; i++){
			int p;
			char c;
			scanf("%d %c", &p, &c);
			if (c == 'L')ans = max(ans, p);
			else{
				ans = max(ans, l - p);
			}
		}

		printf("%d\n", ans);
	}
}