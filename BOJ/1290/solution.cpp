//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//
//	int N, B, U;
//	scanf("%d %d %d", &N, &B, &U);
//
//	int E = 0;
//
//	int t = 0;
//
//	while ((B > 0 || E > 0) && N > 0 && t <= 1000000) {
//
//		t++;
//		// turn1
//		int atk = N;
//
//		if (B > 0) {
//
//			if (N >= U) {
//
//				if (N > E) {
//
//					// enemy first
//					int atk_e = min(E, atk);
//					E -= atk_e;
//					atk -= atk_e;
//
//					int atk_b = min(B, atk);
//					B -= atk_b;
//
//				}
//				else {
//
//					int atk_b = min(B, atk);
//					B -= atk_b;
//					atk -= atk_b;
//
//					int atk_e = min(E, atk);
//					E -= atk_e;
//
//				}
//
//			}
//			else {
//
//				// barrack first
//				int atk_b = min(B, atk);
//				B -= atk_b;
//				atk -= atk_b;
//
//				int atk_e = min(atk, E);
//				E -= atk_e;
//
//			}
//
//		}
//		else {
//
//			E -= min(atk, E);
//
//		}
//
//		// turn 2
//		if (E > 0) {
//			N -= min(N, E);
//		}
//
//		// turn 3
//		if (B > 0)E += U;
//	}
//
//	if (B > 0 || E > 0)t = -1;
//	else if (t > 1000000)t = -1;
//
//	printf("%d\n", t);
//
//}
//
///*
//	3 10000 2
//	3 4 3
//*/

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {


	int N, B, U, E = 0;
	scanf("%d %d %d", &N, &B, &U);

	int t = 0;

	while ((B > 0 || E > 0) && N > 0 && t <= 1000000) {

		t++;

		int atk = N;

		if (B > 0) {
			
			atk--;
			B--;

			int atk_e = min(atk, E);
			E -= atk_e;
			atk -= atk_e;

			B -= atk;

		}
		else {
			E -= min(E, atk);
		}

		if (E > 0)N -= min(N, E);
		if (B > 0)E += U;

	}

	if (E > 0 || B > 0 || t > 1000000)t = -1;

	printf("%d\n", t);

}