#include <stdio.h>
#include <string.h>

char str[10];

int main() {

	int ret = 0;
	int cmd = -1;

	while (scanf("%s", str) == 1) {

		if (str[0] == '=')break;
		else if (str[0] >= '0' && str[0] <= '9') {
			
			int s = strlen(str);

			int v = 0;

			for (int i = 0; i < s; i++) {
				v = v * 10 + str[i] - '0';
			}

			if (cmd == -1)ret = v;
			else{
				if (cmd == '+')ret += v;
				else if (cmd == '-')ret -= v;
				else if (cmd == '*')ret *= v;
				else
					ret /= v;
			}

		}
		else {
			cmd = str[0];
		}


	}

	printf("%d\n", ret);

}