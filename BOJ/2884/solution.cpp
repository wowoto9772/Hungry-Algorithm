#include <stdio.h>

int main() {

	int h, m;
	scanf("%d %d", &h, &m);

	m -= 45;

	if (m < 0) {
	
		h--;
		m += 60;

	}

	if (h < 0)h += 24;


	printf("%d %d\n", h, m);

}