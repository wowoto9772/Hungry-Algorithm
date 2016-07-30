#include <stdio.h>

long long S[1003], V[1003];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n, m;

		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++){ scanf("%lld", &S[i]); }
		for (int i = 1; i <= n; i++){ scanf("%lld", &V[i]); }

		long long l = 1, r = 9999001000001, md;

		long long ans = 0;

		while (l <= r){
			md = (l + r) / 2;

			long long pay = 0;

			for (int i = 1; i <= n; i++){
				long long k = md - S[i];
				if (k < 0)continue;

				int c = 0;
				if (k%V[i])c++;
				k /= V[i];
				k += c;

				pay += k;
				if (pay > m)break;
			}

			if (pay > m)r = md - 1;
			else{
				l = md + 1;
				ans = ans < md ? md : ans;
			}
		}

		printf("%lld\n", ans);
	}
}