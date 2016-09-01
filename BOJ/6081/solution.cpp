#include <stdio.h>

int s[503];

int main(){

	int n, q;
	scanf("%d %d", &n, &q);

	for(int i=1; i<=n; i++){
		scanf("%d", &s[i]);
		s[i] += s[i-1];
	}

	while(q--){
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d\n", s[b] - s[a-1]);
	}

}
