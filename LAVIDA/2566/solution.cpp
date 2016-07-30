#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

char str[54321];

void print(int x, int y) {
	while (y > 9) {
		y -= 9;
		printf("9%c", x);
	}
	if (y == 1)printf("1%c1", x);
	else
		printf("%d%c", y, x);
}

int main() {

	while (fgets(str, 50000, stdin)) {

		int s = strlen(str);
		int x = str[0], y = 1;

		vector <char> out;

		for (int i = 1; i < s; i++) {
			if (x == str[i]) {
				y++;
			}
			else {
				if (y == 1) {
					out.push_back(x);
				}
				else {
					if (!out.empty()) {
						printf("1");
						for (int j = 0; j < out.size(); j++) {
							if (out[j] == '1')printf("11");
							else
								printf("%c", out[j]);
						}
						printf("1");
						out.clear();
					}
					print(x, y);
				}
				x = str[i];
				y = 1;
			}
		}

		if (!out.empty()) {
			printf("1");
			for (int j = 0; j < out.size(); j++) {
				if (out[j] == '1')printf("11");
				else
					printf("%c", out[j]);
			}
			printf("1");
			out.clear();
		}

		if(y != 1)print(x, y);
		printf("\n");

	}

}