// if n : 1
//	if x > 1 second player lose (first win)
//	else first player lose (second win)

// if n : 2

#include <stdio.h>

char str[2][10] = { "koosaga", "cubelover" };

int main() {

	int f = 0;

	int n;
	scanf("%d", &n);

	while (n--) {

		int x;
		scanf("%d", &x);

		if (x == 1)f ^= 1;

	}

	printf("%s\n", str[f]);

}

// koosaga first