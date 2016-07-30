//#include <stdio.h>
//#include <string.h>
//
//char str[103];
//
//int main() {
//
//	int t;
//	scanf("%d", &t);
//
//	int tc = 0;
//
//	while (t--) {
//
//		scanf("%s", str);
//
//		int s = strlen(str);
//
//		int top = 0;
//		int c = 0;
//		int stb = str[0];
//
//		int x[103] = { 0 };
//
//		for (int i = 0; i < s; i++) {
//			if (stb == str[i])c++;
//			else {
//				x[top++] = i;
//				stb = str[i];
//				c = 1;
//			}
//		}
//
//		x[top++] = s - 1;
//
//		c = 0;
//
//		// leftmost to rightmost
//		for (int i = 0; i < top; i++) {
//			if (i == top - 1) {
//				if (str[0] == '-')c++;
//			}
//			else {
//				c++;
//				for (int j = 0; j <= x[i]; j++) {
//					if (str[j] == '+')str[j] = '-';
//					else
//						str[j] = '+';
//				}
//			}
//		}
//
//		printf("Case #%d: %d\n", ++tc, c);
//
//	}
//
//}

#include <stdio.h>
#include <string.h>

char str[103];

int main() {

	int t;
	scanf("%d", &t);

	int tc = 0;

	while (t--) {

		scanf("%s", str);

		int s = strlen(str);

		int c = 0;
		// rightmost to leftmost
		for (int i = s - 1; i >= 0; i--) {
			if (str[i] == '-') {
				c++;
				for (int j = i; j >= 0; j--) {
					if (str[j] == '+')str[j] = '-';
					else
						str[j] = '+';
				}
			}
		}

		printf("Case #%d: %d\n", ++tc, c);

	}

}