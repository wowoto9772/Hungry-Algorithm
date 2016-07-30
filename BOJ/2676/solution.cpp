#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int b, c;
		scanf("%d %d", &b, &c);

		if (!c || c == b)printf("1\n");
		else {
			if (c > b / 2)c = b - c;

			int d = b - 1, s = 1, p = 0;

			while (p < c && d) {
				s += d;
				p++;
				d -= 2;
			}

			printf("%d\n", s);
		}
	}
}