#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		int a;
		bool flag = false;
		for (int j = 1; j <= 10; j++){
			scanf("%d", &a);
			if ((j - 1) % 5 + 1 != a)flag = true;
		}
		if (!flag)printf("%d\n", i);
	}
}

/*
	Dr. L decided to retest the students who got a perfect score
*/