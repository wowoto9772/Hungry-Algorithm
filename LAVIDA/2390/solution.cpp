#include <stdio.h>
#include <algorithm>

using namespace std;

int I[100003];
int P[1000003];

int main()
{
	freopen("large_dat10.in", "r", stdin);
	freopen("large_dat10.out", "w", stdout);
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%d", &I[i]);
		P[I[i]]++;
	}

	sort(I + 1, I + 1 + n);

	long long a = -1, b = -1;

	for (int i = n; i > 1; i--){
		if (P[I[i]] % 2){
			if (I[i - 1] + 1 == I[i]){
				P[I[i]]--;
				P[I[i - 1]]++;
			}
		}
	}

	long long ans = 0;

	for (int i = n; i >= 1; i--){
		if (P[I[i]] >= 2){
			if (a == -1){
				a = I[i];
				P[I[i]] -= 2;
				if (P[I[i]] >= 2){
					b = I[i];
					P[I[i]] -= 2;
					ans += a * b;
					a = b = -1;
					i++;
				}
			}
			else if (b == -1){
				b = I[i];
				P[I[i]] -= 2;
				ans += a * b;
				a = b = -1;
				i++;
			}
		}
	}

	if (ans)printf("%lld\n", ans);
	else
		printf("hungry\n");
}