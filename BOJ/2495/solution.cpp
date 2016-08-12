#include <stdio.h>
#include <algorithm>

using namespace std;

char str[11];

int main() {

	for (int i = 0; i < 3; i++) {
		
		scanf("%s", str);

		int m = 1, p = str[0];

		int x = 0;

		for (int j = 1; j < 8; j++) {
			if (p == str[j])m++;
			else {
				x = max(x, m);
				p = str[j];
				m = 1;
			}
		}

		x = max(x, m);

		printf("%d\n", x);

	}

}