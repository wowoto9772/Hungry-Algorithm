#include <stdio.h>
#define MAX 1000000

bool p[1000003];
int ap[1000003];
int sp[1000003];

int main() {

	for (int i = 2; i*i <= MAX; i++) {
		if (p[i])continue;
		for (int j = i*i; j <= MAX; j += i)p[j] = true;
	}

	int top = 0;
	for (int i = 2; i <= MAX; i++) {
		ap[i] = ap[i - 1];
		sp[i] = sp[i - 1];
		if (!p[i]) {
			ap[i]++;
			if (i % 4 == 1)sp[i]++;
			else if (i == 2)sp[i]++;
		}
	}

	int a, b;
	while (scanf("%d %d", &a, &b) == 2) {

		if (a == -1 && a == b)break;

		int ca = a, cb = b;

		if (a < 0)ca = 1;
		if (b < 1)cb = 1;

		printf("%d %d %d %d\n", a, b, (ap[cb] - ap[ca - 1]), (sp[cb] - sp[ca - 1]));

	}

}