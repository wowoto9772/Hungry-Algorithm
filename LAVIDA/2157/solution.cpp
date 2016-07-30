//#include <stdio.h>
//#include <vector>
//
//using namespace std;
//
//int A(int a){ return a < -a ? -a : a; }
//
//int main(){
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int m;
//		scanf("%d", &m);
//
//		bool fall[202] = { 0 };
//
//		for (int i = 1; i <= m; i++){
//			int a;
//			scanf("%d", &a);
//			fall[a] = true;
//		}
//
//		int l, r;
//		for (int i = 1; i <= 200; i++){
//			if (fall[i]){
//				l = i;
//				break;
//			}
//		}
//		for (int i = 200; i >= 1; i--){
//			if (fall[i]){
//				r = i;
//				break;
//			}
//		}
//
//		int c;
//		scanf("%d", &c);
//
//		vector <int> L, R;
//
//		int p = c;
//
//		bool lf[202], rf[202];
//		for (int i = 1; i <= 200; i++)lf[i] = rf[i] = fall[i];
//
//		int lm = 0, rm = 0;
//		for (int i = c; i >= l; i--){
//			if (lf[i]){
//				lm += A(p - i);
//				p = i;
//				lf[i] = false;
//				L.push_back(i);
//			}
//		}
//		for (int i = l; i <= r; i++){
//			if (lf[i]){
//				lm += A(p - i);
//				p = i;
//				lf[i] = false;
//				L.push_back(i);
//			}
//		}
//
//		p = c;
//		for (int i = c; i <= r; i++){
//			if (rf[i]){
//				rm += A(p - i);
//				p = i;
//				rf[i] = false;
//				R.push_back(i);
//			}
//		}
//		for (int i = r; i >= l; i--){
//			if (rf[i]){
//				rm += A(p - i);
//				p = i;
//				rf[i] = false;
//				R.push_back(i);
//			}
//		}
//
//		if (lm > rm){
//			for (int i = 0; i < R.size()-1; i++){
//				printf("%d ", R[i]);
//			}printf("%d\n", R[R.size()-1]);
//		}
//		else if(lm < rm){
//			for (int i = 0; i < L.size() - 1; i++){
//				printf("%d ", L[i]);
//			}printf("%d\n", L[L.size() - 1]);
//		}
//		else{
//			bool left = false, right = false;
//			for (int i = 0; !left && !right && i < L.size() - 1; i++){
//				if (L[i] < R[i]){
//					left = true;
//				}
//				else if (L[i] > R[i]){
//					right = true;
//				}
//			}
//			if (!left && !right){
//				if (L[L.size() - 1] < R[R.size() - 1]){
//					left = true;
//				}
//				else{
//					right = true;
//				}
//			}
//
//			if (right){
//				for (int i = 0; i < R.size() - 1; i++){
//					printf("%d ", R[i]);
//				}printf("%d\n", R[R.size() - 1]);
//			}
//			else{
//				for (int i = 0; i < L.size() - 1; i++){
//					printf("%d ", L[i]);
//				}printf("%d\n", L[L.size() - 1]);
//			}
//		}
//	}
//}

#include <stdio.h>
#include <vector>

using namespace std;

int A(int a){ return a < -a ? -a : a; }

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int m;
		scanf("%d", &m);

		bool fall[202] = { 0 };

		for (int i = 1; i <= m; i++){
			int a;
			scanf("%d", &a);
			fall[a] = true;
		}

		int l, r;
		for (int i = 1; i <= 200; i++){
			if (fall[i]){
				l = i;
				break;
			}
		}
		for (int i = 200; i >= 1; i--){
			if (fall[i]){
				r = i;
				break;
			}
		}

		int c;
		scanf("%d", &c);

		vector <int> L, R;

		int p = c;

		bool lf[202], rf[202];
		for (int i = 1; i <= 200; i++)lf[i] = rf[i] = fall[i];

		int lm = 0, rm = 0;
		for (int i = c; i >= l; i--){
			if (lf[i]){
				lm += A(p - i);
				p = i;
				lf[i] = false;
				L.push_back(i);
			}
		}
		for (int i = l; i <= r; i++){
			if (lf[i]){
				lm += A(p - i);
				p = i;
				lf[i] = false;
				L.push_back(i);
			}
		}

		p = c;
		for (int i = c; i <= r; i++){
			if (rf[i]){
				rm += A(p - i);
				p = i;
				rf[i] = false;
				R.push_back(i);
			}
		}
		for (int i = r; i >= l; i--){
			if (rf[i]){
				rm += A(p - i);
				p = i;
				rf[i] = false;
				R.push_back(i);
			}
		}

		if (lm > rm){
			for (int i = 0; i < R.size() - 1; i++){
				printf("%d ", R[i]);
			}printf("%d\n", R[R.size() - 1]);
		}
		else{
			for (int i = 0; i < L.size() - 1; i++){
				printf("%d ", L[i]);
			}printf("%d\n", L[L.size() - 1]);
		}
	}
}