#include <stdio.h>

int s[503], S[503];

int main()
{

	for (int i = 1; i <= 500; i++){
		s[i] = i*(i + 1) / 2;
		S[i] = S[i - 1] + s[i];
	}

	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		printf("%d\n", S[n]);
	}
}