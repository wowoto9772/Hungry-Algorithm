#include <stdio.h>

bool p[100003];
int P[100003];
int top;

int main()
{
	for (int i = 2; i*i <= 100000; i++){
		if (!p[i]){
			for (int j = i + i; j <= 100000; j += i){
				p[j] = true;
			}
		}
	}

	for (int i = 2; i <= 100000; i++){
		if (!p[i])P[i] = P[i - 1] + 1;
		else
			P[i] = P[i - 1];
	}

	int t;
	while (scanf("%d", &t) == 1){

		while (t--){
			int a, b;
			scanf("%d %d", &a, &b);

			if (a == 0)a = 1;

			printf("%d\n", P[b] - P[a - 1]);
		}

	}
}