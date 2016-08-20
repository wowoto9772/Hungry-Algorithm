#include <stdio.h>

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	bool flag = false;

	for (int i = 0; !flag && i < n; i++) {
		for (int j = 0; !flag && j < m; j++) {
			char sexy;
			scanf(" %c", &sexy);
			if (sexy == 'C' || sexy == 'M' || sexy == 'Y')flag = true;
		}
	}

	if (flag) {
		printf("#Color\n");
	}
	else {
		printf("#Black&White\n");
	}

}
