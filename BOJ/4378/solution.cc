#include <cstdio>
#include <cstring>

using namespace std;

char str[][15] = { "`1234567890-=", "QWERTYUIOP[]\\", "ASDFGHJKL;'", "ZXCVBNM,./" };
char in[54321];

int main() {

	while (fgets(in, 50000, stdin)) {

		int s = strlen(in);

		for (int i = 0; i < s; i++) {
			if (in[i] == ' ')printf(" ");
			else {
				for (int j = 0; j < 4; j++) {
					int s_ = strlen(str[j]);
					for (int k = 0; k < s_; k++) {
						if (str[j][k] == in[i]) {
							printf("%c", str[j][k - 1]);
						}
					}
				}
			}

		}
		printf("\n");
	}
}
