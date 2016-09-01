#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	long long N, M, R;
	while (scanf("%lld %lld %lld", &N, &M, &R) == 3){

		long long l = 1, r = 100 * M * N, m;
		long long ans = r;

		while (l <= r){

			m = (l + r) / 2;
			long long k = N;

			for (int i = 1; i <= M; i++){
				long long a = k * R;
				if (a % 100)a += 100;
				a /= 100;
				k -= (m - a);
				if (k < 0){
					break;
				}
			}

			if (k <= 0){
				ans = min(ans, m);
				r = m - 1;
			}
			else{
				l = m + 1;
			}
		}

		printf("%lld\n", ans);
	}
}
