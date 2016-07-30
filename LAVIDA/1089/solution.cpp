#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n, k;
		scanf("%d %d", &n, &k);
		k = n - k > k ? k : n - k;

		int m = 1;

		for (int i = 1; i <= k; i++){
			m *= n--;
		}
		for (int i = 2; i <= k; i++)m /= i;

		printf("%d\n", m);
	}
}