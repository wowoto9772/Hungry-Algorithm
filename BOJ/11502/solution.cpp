#include <stdio.h>

bool p[1003];
int P[303];

int main() {

	int top = 0;

	for (int i = 2; i <= 1000; i++) {
		if (!p[i]) {
			P[top++] = i;
			for (int j = i + i; j <= 1000; j += i) {
				p[j] = true;
			}
		}
	}

	int t;
	scanf("%d", &t);

	while (t--) {

		int a;
		scanf("%d", &a);

		bool flag = false;

		for (int i = 0; !flag && i < top; i++) {
			for (int j = i; !flag && j < top; j++) {
				int b = a - P[i] - P[j];
				if (P[j] <= b) {
					if (!p[b]) {
						printf("%d %d %d\n", P[i], P[j], b);
						flag = true;
					}
				}
				else {
					break;
				}			 
			}
		}

	}

}