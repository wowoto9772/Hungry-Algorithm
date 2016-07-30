//#include <stdio.h>
//
//int main() {
//
//	int t;
//	scanf("%d", &t);
//
//	while (t--) {
//
//		int b;
//		scanf("%d", &b);
//
//		int ret = 0;
//
//		char d;
//		scanf("%c", &d);
//
//		while (scanf("%c", &d) == 1) {
//
//			if (d == '\n')break;
//			ret = ret + d - '0';
//			// ret = ret * b + d - '0';
//			ret %= (b - 1);
//
//		}
//
//		printf("%d\n", ret);
//
//	}
//
//}

#include <stdio.h>
#include <ctype.h>

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int b;
		scanf("%d", &b);

		int ret = 0;

		char d;
		scanf("%c", &d);

		while (d = getchar()) {

			if (d == '\n')break;

			ret = ret + d - '0';
			// ret = ret * b + d - '0';
			ret %= (b - 1);

		}


		// while(isdigit(d = getchar()), then ignore '\n'

		printf("%d\n", ret);

	}

}