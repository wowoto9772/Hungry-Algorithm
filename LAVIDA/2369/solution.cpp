#include <stdio.h>
#include <string.h>

char str[13][23];
int P[13];

int main()
{
	int M, N;
	scanf("%d %d", &M, &N);

	for (int i = 1; i <= M; i++){
		scanf(" %s %d", str[i], &P[i]);
		int a = strlen(str[i]);

		for (int j = 0; j < a; j++)if (str[i][j] >= 'A' && str[i][j] <= 'Z')str[i][j] += 'a' - 'A';
	}

	for (int i = 1; i <= N; i++){
		int c = 0;
		char str2[23] = { 0 };
		while (scanf("%s", str2) == 1 && strcmp(str2, ".")){
			int s = strlen(str2);
			for (int j = 0; j < s; j++)if (str2[j] >= 'A' && str2[j] <= 'Z')str2[j] += 'a' - 'A';

			bool f = false;
			
			for (int j = 1; j <= M; j++){
				if (!strcmp(str2, str[j])){
					c += P[j];
					f = true;
					break;
				}
			}

			if (!f)c += s * 2;
		}

		printf("%d\n", c);
	}
}