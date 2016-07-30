#include <stdio.h>
#include <algorithm>

using namespace std;

long long I[1003];

int main()
{
	//freopen("B-small-practice.in", "r", stdin);
	//freopen("B-small-practice.out", "w", stdout);
	//freopen("B-large-practice.in", "r", stdin);
	//freopen("B-large-practice.out", "w", stdout);
	int tc_;
	scanf("%d", &tc_);

	for (int tc = 1; tc <= tc_; tc++){
		long long n, m;
		scanf("%lld %lld", &n, &m);

		long long M = 0;
		for (int i = 1; i <= n; i++){
			scanf("%lld", &I[i]);
			M = M > I[i] ? M : I[i];
		}

		long long l = 0, r = m * M, md;
		long long p = 0;

		while (l <= r){
			md = (l + r) / 2;
			p = n;
			for (int i = 1; i <= n; i++){
				p += md / I[i];
				if (p > m)break;
			}
			if (p >= m)r = md - 1;
			else if (p < m)l = md + 1;
		}


		long long T[1003] = { 0 };
		md--;
		p = n;
		for (int i = 1; i <= n; i++){
			T[i] = md / I[i] * I[i];
			p += md / I[i];
		}

		int ans = 0;
		while (p < m){
			md++;
			for (int i = 1; i <= n; i++){
				if (md%I[i])continue;
				else{
					p++;
					if (p == m){
						ans = i;
						break;
					}
					T[i] += I[i];
				}
			}
		}


		printf("Case #%d: %d\n", tc, ans);
	}
}
