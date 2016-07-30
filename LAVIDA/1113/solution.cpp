//#include <stdio.h>
//
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class ele{
//public:
//	int a, p;
//	bool operator<(const ele &A)const{
//		if (a == A.a)return p < A.p;
//		return a < A.a;
//	}
//}I[100003];
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
//	int n;
//	scanf("%d", &n);
//
//	BIT Tree(n);
//
//	for (int i = 0; i < n; i++){
//		scanf("%d", &I[i].a);
//		I[i].p = i+1;
//		Tree.Update(i+1, 1);
//	}
//
//	sort(I, I + n); // ascending order
//
//	long long ans = 0;
//
//	for (int i = 0; i < n; i++){
//
//		ans += Tree.Sum(I[i].p)-1;
//		Tree.Update(I[i].p, -1);
//
//	}
//
//	printf("%lld\n", ans);
//
//}

#include <stdio.h>

#include <vector>
#include <algorithm>

using namespace std;

class ele{
public:
	int a, p;
	bool operator<(const ele &A)const{
		if (a == A.a)return p < A.p;
		return a < A.a;
	}
}I[100003];

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
	int n;
	scanf("%d", &n);

	BIT Tree(n);

	for (int i = 0; i < n; i++){
		scanf("%d", &I[i].a);
		I[i].p = i + 1;
		Tree.Update(i + 1, 1);
	}

	sort(I, I + n); // ascending order

	long long ans = 0;

	for (int i = 0; i < n; i++){

		ans += Tree.Sum(I[i].p - 1);
		Tree.Update(I[i].p, -1);

	}

	printf("%lld\n", ans);

}