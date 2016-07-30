#include <stdio.h>
#include <string.h>

char x[20];

int main() {

	scanf("%s", x);
	int s = strlen(x);
	
	int v;

	if (s >= 2) {
		if (x[0] == '0' && x[1] == 'x') {
			sscanf(x, "%x", &v);
		}
		else if (x[0] == '0') {
			v = 0;
			int k = 1;
			for (int j = s - 1; j >= 1; j--) {
				v += k * (x[j] - '0');
				k *= 8;
			}
		}
		else {
			sscanf(x, "%d", &v);
		}
	}
	else {
		sscanf(x, "%d", &v);
	}

	printf("%d\n", v);

}