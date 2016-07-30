//#include <stdio.h>
//
//int dp[10003][3], I[10003];
//int max(int a, int b){ return a < b ? b : a; }
//
//int main(){
//	int n;
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++){
//		scanf("%d", &I[i]);
//	}
//	dp[1][1] = I[1];
//	for (int i = 2; i <= n; i++){
//		dp[i][1] = dp[i - 1][1] + I[i];
//		dp[i][2] = max(dp[i - 2][1], dp[i - 2][2]) + I[i - 1] * I[i];
//	}
//	printf("%d\n", max(dp[n][1], dp[n][2]));
//}
/*
#include <stdio.h>
#include <algorithm>

using namespace std;

long long P[10003], M[10003];

int main(){
int n;
scanf("%d", &n);

int zero = 0;
int pt = 0, mt = 0;
for (int i = 1; i <= n; i++){
long long a;
scanf("%lld", &a);
if (a){
if(a > 0)P[pt++] = a;
else{
M[mt++] = a;
}
}
else{
zero++;
}
}

sort(P, P + pt);
sort(M, M + mt);

long long ans = 0;

for (int i = pt - 1; i >= 0; ){
if (i){
if (P[i] == P[i - 1]){
ans += P[i];
i--;
}
else{
ans += P[i] * P[i - 1];
i -= 2;
}
}
else{
ans += P[i];
i--;
}
}

for (int i = 0; i < mt; ){
if (i + 1 < mt){
if (M[i] == M[i + 1]){
if (zero){
zero--;
}
else{
ans += M[i];
}
i++;
}
else{
ans += M[i] * M[i + 1];
i += 2;
}
}
else{
if(!zero)ans += M[i];
i++;
}
}

printf("%lld\n", ans);
}
*/

#include <stdio.h>
#include <algorithm>

using namespace std;

long long P[10003], M[10003];

int main(){
	int n;
	while (scanf("%d", &n) == 1){

		int zero = 0;
		int pt = 0, mt = 0;
		for (int i = 1; i <= n; i++){
			long long a;
			scanf("%lld", &a);
			if (a){
				if (a > 0)P[pt++] = a;
				else{
					M[mt++] = a;
				}
			}
			else{
				zero++;
			}
		}

		sort(P, P + pt);
		sort(M, M + mt);

		long long ans = 0;

		for (int i = pt - 1; i >= 0;){
			if (i){
				if (P[i - 1] == 1){
					ans += P[i];
					i--;
				}
				else{
					ans += P[i] * P[i - 1];
					i -= 2;
				}
			}
			else{
				ans += P[i];
				i--;
			}
		}

		for (int i = 0; i < mt;){
			if (i + 1 < mt){
				ans += M[i] * M[i + 1];
				i += 2;
			}
			else{
				if (!zero)ans += M[i];
				i++;
			}
		}

		printf("%lld\n", ans);
	}

}

/*
2
1 2
2가 아니라 3
*/