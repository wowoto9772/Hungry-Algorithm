#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int h, m;
	scanf("%d:%d", &h, &m);

	int t = h * 60 + m;

	char flag;
	double stb;
	scanf(" UTC%c%lf", &flag, &stb);
	if (flag == '-')t += 60 * stb;
	else{
		t -= 60 * stb;
	}

	for (int i = 1; i <= n; i++){
		scanf(" UTC%c%lf", &flag, &stb);

		int tt = (int)stb * 60 + 60 * (stb - (int)stb);
		if (flag == '-')tt = t - tt;
		else
			tt = t + tt;

		if (tt >= 60 * 24)tt %= 60 * 24;
		while(tt < 0)tt += 60 * 24;

		printf("%02d:%02d\n", tt / 60, tt % 60);
	}
}