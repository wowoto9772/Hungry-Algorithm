#include <stdio.h>

int main() {

	int n = 8;

	int p;
	scanf("%d", &p);

	bool ass = false, des = false;

	for (int i = 2; i <= n; i++) {
		int c;
		scanf("%d", &c);

		if (p < c)ass = true;
		else if (p > c)des = true;
		p = c;
	}

	if (ass && des)printf("mixed\n");
	else if (ass)printf("ascending\n");
	else if (des)printf("descending\n");
	else {
		printf("mixed\n");
	}
}