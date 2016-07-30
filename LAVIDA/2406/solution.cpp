#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	while (t--){
		int J = 0, M = 0;
		int oj = 0, om = 0;
		int a;
		for (int i = 1; i <= 3; i++){
			scanf("%d", &a);
			if (a % 2)oj++;
			J += a;
		}
		for (int i = 1; i <= 3; i++){
			scanf("%d", &a);
			if (a % 2)om++;
			M += a;
		}
		if (J == M){
			if (oj == om)printf("Draw\n");
			else if (oj > om)printf("Joo-Ahn wins\n");
			else
				printf("Min-Gwang wins\n");
		}
		else if (J > M)printf("Joo-Ahn wins\n");
		else
			printf("Min-Gwang wins\n");
	}
}