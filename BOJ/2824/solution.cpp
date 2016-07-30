////#include <stdio.h>
////
////#include <map>
////#include <algorithm>
////#include <vector>
////
////#define ll long long
////#define mod 1000000000
////
////using namespace std;
////
////int main(){
////
////	int a, b;
////	scanf("%d %d", &a, &b);
////
////	int x;
////	map <int, int> ca;
////
////	vector <int> A;
////	for (int i = 1; i <= a; i++){
////		scanf("%d", &x);
////		for (int j = 2; j*j <= x; j++){
////			if (x%j)continue;
////			int c = 0;
////			while (!(x%j)){
////				x /= j;
////				c++;
////			}
////			if (!ca[j])A.push_back(j);
////			ca[j] += c;
////		}
////		if (x != 1){
////			if (!ca[x])A.push_back(x);
////			ca[x]++;
////		}
////	}
////
////	map <int, int> cb;
////
////	for (int i = 1; i <= b; i++){
////		scanf("%d", &x);
////		for (int j = 2; j*j <= x; j++){
////			if (x%j)continue;
////			int c = 0;
////			while (!(x%j)){
////				x /= j;
////				c++;
////			}
////			cb[j] += c;
////		}
////		if (x != 1){
////			cb[x]++;
////		}
////	}
////
////	sort(A.begin(), A.end());
////
////	ll ans = 1;
////	bool flag = false;
////
////	for (int i = 0; i < A.size(); i++){
////		int m = min(ca[A[i]], cb[A[i]]);
////		for (int j = 1; j <= m; j++){
////			ans *= A[i];
////			if (ans >= 1000000000){
////				flag = true;
////				ans %= mod;
////			}
////		}
////	}
////
////	if (flag){
////		printf("%09lld\n", ans);
////	}
////	else{
////		printf("%lld\n", ans);
////	}
////}
//
//#include <stdio.h>
//
//#include <map>
//#include <algorithm>
//#include <vector>
//
//#define ll long long
//#define mod 1000000000
//
//using namespace std;
//
//int main(){
//
//	int a, b;
//	scanf("%d %d", &a, &b);
//
//	int x;
//	map <int, int> ca;
//
//	vector <int> A;
//	for (int i = 1; i <= a; i++){
//		scanf("%d", &x);
//		for (int j = 2; j*j <= x; j++){
//			if (x%j)continue;
//			int c = 0;
//			while (!(x%j)){
//				x /= j;
//				c++;
//			}
//			if (!ca[j])A.push_back(j);
//			ca[j] += c;
//		}
//		if (x != 1){
//			if (!ca[x])A.push_back(x);
//			ca[x]++;
//		}
//	}
//
//	map <int, int> cb;
//
//	for (int i = 1; i <= b; i++){
//		scanf("%d", &x);
//		for (int j = 2; j*j <= x; j++){
//			if (x%j)continue;
//			int c = 0;
//			while (!(x%j)){
//				x /= j;
//				c++;
//			}
//			cb[j] += c;
//		}
//		if (x != 1){
//			cb[x]++;
//		}
//	}
//
//	sort(A.begin(), A.end());
//
//	ll ans = 1;
//	bool flag = false;
//
//	for (int i = 0; i < A.size(); i++){
//		int m = min(ca[A[i]], cb[A[i]]);
//		for (int j = 1; j <= m; j++){
//			ans *= A[i];
//			if (ans >= 1000000000){
//				flag = true;
//				ans %= mod;
//			}
//		}
//	}
//
//	if (flag){
//		printf("%09lld\n", ans);
//	}
//	else{
//		printf("%lld\n", ans);
//	}
//}
//
//// 10/0000/0000 => 5000 0000 primes

//#include <stdio.h>
//
//#include <map>
//#include <algorithm>
//#include <vector>
//
//#define ll long long
//#define mod 1000000000
//
//using namespace std;
//
//int main(){
//
//	int a, b;
//	scanf("%d %d", &a, &b);
//
//	int x;
//	map <int, int> ca;
//
//	vector <int> A;
//	for (int i = 1; i <= a; i++){
//		scanf("%d", &x);
//		for (int j = 2; j*j <= x; j++){
//			if (x%j)continue;
//			int c = 0;
//			while (!(x%j)){
//				x /= j;
//				c++;
//			}
//			if (!ca[j])A.push_back(j);
//			ca[j] += c;
//		}
//		if (x != 1){
//			if (!ca[x])A.push_back(x);
//			ca[x]++;
//		}
//	}
//
//	map <int, int> cb;
//
//	for (int i = 1; i <= b; i++){
//		scanf("%d", &x);
//		for (int j = 2; j*j <= x; j++){
//			if (x%j)continue;
//			int c = 0;
//			while (!(x%j)){
//				x /= j;
//				c++;
//			}
//			cb[j] += c;
//		}
//		if (x != 1){
//			cb[x]++;
//		}
//	}
//
//	sort(A.begin(), A.end());
//
//	ll ans = 1;
//	bool flag = false;
//
//	for (int i = 0; i < A.size(); i++){
//		int m = min(ca[A[i]], cb[A[i]]);
//		for (int j = 1; j <= m; j++){
//			ans *= A[i];
//			if (ans >= 1000000000){
//				flag = true;
//				ans %= mod;
//			}
//		}
//	}
//
//	if (flag){
//		printf("%09lld\n", ans);
//	}
//	else{
//		printf("%lld\n", ans);
//	}
//}

#include <stdio.h>

#include <map>
#include <algorithm>
#include <vector>

#define ll long long
#define mod 1000000000

using namespace std;

int main(){

	int a;
	scanf("%d", &a);

	int x;
	map <int, int> ca;

	vector <int> A;
	for (int i = 1; i <= a; i++){
		scanf("%d", &x);
		for (int j = 2; j*j <= x; j++){
			if (x%j)continue;
			int c = 0;
			while (!(x%j)){
				x /= j;
				c++;
			}
			if (!ca[j])A.push_back(j);
			ca[j] += c;
		}
		if (x != 1){
			if (!ca[x])A.push_back(x);
			ca[x]++;
		}
	}

	int b;
	scanf("%d", &b);

	map <int, int> cb;

	for (int i = 1; i <= b; i++){
		scanf("%d", &x);
		for (int j = 2; j*j <= x; j++){
			if (x%j)continue;
			int c = 0;
			while (!(x%j)){
				x /= j;
				c++;
			}
			cb[j] += c;
		}
		if (x != 1){
			cb[x]++;
		}
	}

	sort(A.begin(), A.end());

	ll ans = 1;
	bool flag = false;

	for (int i = 0; i < A.size(); i++){
		int m = min(ca[A[i]], cb[A[i]]);
		for (int j = 1; j <= m; j++){
			ans *= A[i];
			if (ans >= 1000000000){
				flag = true;
				ans %= mod;
			}
		}
	}

	if (flag){
		printf("%09lld\n", ans);
	}
	else{
		printf("%lld\n", ans);
	}
}

// 10/0000/0000 => 5000 0000 primes