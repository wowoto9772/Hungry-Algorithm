#include <stdio.h>

int main() {

	int t;
	scanf("%d", &t);

	int m = 0;

	while (t--) {
		if (m > 1)m += 2;
		else
			m++;
	}

	m %= 2;

	if(m)printf("")

}