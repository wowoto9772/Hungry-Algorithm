#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n, a;
		scanf("%d", &n);

		int s = 0, max = -1, min = 10001;

		for (int i = 1; i <= n; i++){
			scanf("%d", &a);
			if (max < a)max = a;
			if (min > a)min = a;
			s += a;
		}

		s -= (max + min);
		s *= 1000;
		s /= (n - 2);
		if (s % 10 >= 5)s += 10;
		s /= 10;
		double s_ = s;
		s_ /= 100;
		printf("%.2lf\n", s_);
	}
}