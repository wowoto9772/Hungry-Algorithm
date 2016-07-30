//#include <stdio.h>
//#include <vector>
//
//using namespace std;
//
//int main() {
//
//	int t;
//	scanf("%d", &t);
//
//	while (t--) {
//
//		int v;
//		scanf("%d", &v);
//
//		vector <int> p, c;
//
//		bool flag = false;
//
//		for (int i = 2; i*i <= v; i++) {
//			if (v%i)continue;
//
//			if (i >= 11) {
//
//				flag = true;
//				break;
//
//			}
//
//			p.push_back(i);
//			c.push_back(1);
//			
//			v /= i;
//
//			while ((!v%i)) {
//
//				v /= i;
//				c.back()++;
//
//			}
//		}
//
//		if (v != 1) {
//			
//			if (v >= 11)flag = true;
//			else {
//
//				// prime number
//
//				p.push_back(v);
//				c.push_back(1);
//
//			}
//
//		}
//
//		if (flag)printf("-1\n");
//		else {
//
//
//
//		}
//
//	}
//
//}


#include <stdio.h>

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int v;
		scanf("%d", &v);

		if (v == 1)printf("1\n");
		else {

			int c = 0;

			while (v != 1) {

				bool end = true;
				for (int i = 9; i >= 2; i--) {
					if (v%i)continue;

					end = false;

					v /= i;
					c++;
					break;
				}

				if (end)break;

			}

			if (v >= 11)printf("-1\n");
			else {
				printf("%d\n", c);
			}

		}

	}

}