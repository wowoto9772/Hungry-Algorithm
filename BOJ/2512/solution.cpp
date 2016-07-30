#include <stdio.h>

int lm[10003];

int main(){
	int n;
	scanf("%d", &n);

	int max = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", &lm[i]);
		if (max < lm[i])max = lm[i];
	}

	int tot;
	scanf("%d", &tot);

	int l = 1, r = max, m;

	int ans = 0;

	while (l <= r){
		m = (l + r) / 2;

		long long cmp = 0;

		for (int i = 1; i <= n; i++){
			int k = m;
			if (k > lm[i])k = lm[i];
			cmp += k;

			if (cmp > tot)break;
		}

		if (cmp > tot){
			r = m - 1;
		}
		else{
			if (ans < m)ans = m;
			l = m + 1;
		}
	}

	printf("%d\n", ans);
}