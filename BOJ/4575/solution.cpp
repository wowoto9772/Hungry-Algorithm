#include <stdio.h>
#include <string.h>

using namespace std;

char a[2][123];

int main() {

	while (true) {

		fgets(a[0], 120, stdin);
		if (!strcmp(a[0], "END\n") || !strcmp(a[0], "END"))break;
		fgets(a[1], 120, stdin);

		for (int j = 0; j < 2; j++) {

			int s = strlen(a[j]);

			if (a[j][s - 1] == '\n')s--;

			bool chk['Z' + 3] = { 0 };

			bool flag = false;

			for (int i = 0; i < s; i++) {
				if (a[j][i] >= 'A') {
					if (!chk[a[j][i]])chk[a[j][i]] = true;
					else
						flag = true;
				}
			}

			if (!flag) {
				for (int i = 0; i < s; i++)printf("%c", a[j][i]);
				printf("\n");
			}

		}

	}

}