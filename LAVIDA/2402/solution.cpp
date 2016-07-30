#include <stdio.h>

int main()
{
	int s = 0, n = 0;
	for (int i = 1; i <= 3; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		s += a, n += b;
	}printf("%d %d\n", s, n);
}

#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a%b || a%c || a%d)printf("NO\n");
		else
			printf("YES\n");
	}
}