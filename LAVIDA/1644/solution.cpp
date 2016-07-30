#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		long long ans = 0; 
		// you play first

		for (int i = 1; i <= n; i++){
			long long a;
			scanf("%lld", &a);
			while (a & 1)a >>= 1LL;
			// a player must remove at least one stone 
			// from one pile but no more than 
			// half of the number of stones in that pile
			ans ^= a;
		} // The player who cannot make any moves is considered lost

		printf("%s\n", ans ? "YES" : "NO");
	}
}