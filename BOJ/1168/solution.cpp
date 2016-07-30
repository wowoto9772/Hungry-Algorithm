//#include <stdio.h>
//#include <vector>
//
//using namespace std;
//
//class BIT{
//public:
//	vector <int> T;
//	int S;
//	BIT(const int n){
//		S = n;
//		T.resize(S + 1);
//	}
//	void Update(int p, int v){
//		while (p <= S){
//			T[p] += v;
//			p += p & (-p);
//		}
//	}
//	long long Sum(int p){
//		long long ret = 0;
//		while (p > 0){
//			ret += T[p];
//			p -= p & (-p);
//		}return ret;
//	}
//};
//
//int main(){
//	int n, m;
//	scanf("%d %d", &n, &m);
//
//	BIT tree(n);
//
//	for (int i = 1; i <= n; i++){
//		tree.Update(i, 1);
//	}
//
//	printf("<");
//	printf("%d", m);
//	tree.Update(m, -1);
//
//	int cnt = 1;
//	int s = m;
//
//	while (cnt < n){
//		int ri = tree.Sum(n) - tree.Sum(s);
//		if (tree.Sum(n) >= m){
//			if (ri < m){
//				// left
//				int l = 1, r = s, x;
//
//				while (l <= r){
//					x = (l + r) / 2;
//					int cmp = ri + tree.Sum(x);
//					if (cmp >= m)r = x - 1;
//					else
//						l = x + 1;
//				}
//
//				while (ri + tree.Sum(x) < m)x++;
//
//				if (cnt < n)printf(", ");
//				printf("%d", x);
//				tree.Update(x, -1);
//				s = x;
//				cnt++;
//			}
//			else{
//				// right
//				int l = s + 1, r = n, x;
//				while (l <= r){
//					x = (l + r) / 2;
//					int cmp = tree.Sum(x) - tree.Sum(s);
//					if (cmp >= m)r = x - 1;
//					else{
//						l = x + 1;
//					}
//				}
//
//				while (ri + tree.Sum(x) < m)x++;
//
//				if (cnt < n)printf(", ");
//				printf("%d", x);
//				tree.Update(x, -1);
//				s = x;
//				cnt++;
//			}
//		}
//		else{
//			int le = tree.Sum(s);
//			if (tree.Sum(n) == 1){
//				if (ri){
//					printf(", ");
//					for (int i = s; i <= n; i++){
//						if (tree.Sum(i) - tree.Sum(i - 1)){
//							printf("%d", i);
//							break;
//						}
//					}
//					break;
//				}
//				else{
//					printf(", ");
//					for (int i = 1; i <= s; i++){
//						if (tree.Sum(i) - tree.Sum(i - 1)){
//							printf("%d", i);
//							break;
//						}
//					}
//					break;
//				}
//			}
//			else{
//				int rem = m - (m / (le + ri)) * (le + ri);
//				if (rem == 0)rem = ri;
//				if (rem > ri){
//					rem -= ri;
//					// left
//
//					int l = 1, r = s, x;
//
//					while (l <= r){
//						x = (l + r) / 2;
//						int cmp = tree.Sum(x);
//						if (cmp >= rem)r = x - 1;
//						else
//							l = x + 1;
//					}
//
//					while (tree.Sum(x) < rem)x++;
//
//					if (cnt < n)printf(", ");
//					printf("%d", x);
//					tree.Update(x, -1);
//					s = x;
//					cnt++;
//
//				}
//				else{
//					// right
//
//					int l = s + 1, r = n, x;
//					while (l <= r){
//						x = (l + r) / 2;
//						int cmp = tree.Sum(x) - tree.Sum(s);
//						if (cmp >= rem)r = x - 1;
//						else{
//							l = x + 1;
//						}
//					}
//
//					while (tree.Sum(x) - tree.Sum(s) < rem)x++;
//
//					if (cnt < n)printf(", ");
//					printf("%d", x);
//					tree.Update(x, -1);
//					s = x;
//					cnt++;
//				}
//			}
//		}
//	}
//	printf(">");
//}

#include <stdio.h>
#include <vector>

using namespace std;

class BIT{
public:
	vector <int> T;
	int S;
	BIT(const int n){
		S = n;
		T.resize(S + 1);
	}
	void Update(int p, int v){
		while (p <= S){
			T[p] += v;
			p += p & (-p);
		}
	}
	long long Sum(int p){
		long long ret = 0;
		while (p > 0){
			ret += T[p];
			p -= p & (-p);
		}return ret;
	}
};

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	BIT tree(n);

	for (int i = 1; i <= n; i++){
		tree.Update(i, 1);
	}

	printf("<");
	printf("%d", m);
	tree.Update(m, -1);

	int cnt = 1;
	int s = m;

	while (cnt < n){
		int le = tree.Sum(s);
		int ri = tree.Sum(n) - tree.Sum(s);

		int rm;
		if (m % (le + ri)){
			rm = m - m / (le + ri) * (le + ri);
		}
		else{
			rm = m - (m / (le + ri) - 1) * (le + ri);
		}

		int l, r, x;

		if (rm > ri){
			rm -= ri;

			l = 1, r = s, x;
			while (l <= r){
				x = (l + r) / 2;
				int cmp = tree.Sum(x);

				if (cmp >= rm){
					r = x - 1;
				}
				else
					l = x + 1;
			}

			while (tree.Sum(x) < rm)x++;
		}
		else{

			l = s, r = n, x;
			while (l <= r){
				x = (l + r) / 2;
				int cmp = tree.Sum(x) - tree.Sum(s);

				if (cmp >= rm){
					r = x - 1;
				}
				else
					l = x + 1;
			}

			while (tree.Sum(x) - tree.Sum(s) < rm)x++;
		}
		if (cnt < n)printf(", ");
		printf("%d", x);
		tree.Update(x, -1);
		s = x;
		cnt++;
	}
	printf(">");
}