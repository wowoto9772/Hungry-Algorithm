//#include <stdio.h>
//#include <limits.h>
//#include <math.h>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class ele{
//public:
//	int x, y;
//	bool operator<(const ele &A)const{
//		return x < A.x;
//	}
//}I[100003];
//
//vector <ele> A;
//
//int m(int a, int b){ return a < b ? a : b; }
//
//int ECP(int a, int b){
//	if (a == b)return INT_MAX;
//	if (a + 1 == b)return (I[a].x - I[b].x)*(I[a].x - I[b].x) + (I[a].y - I[b].y)*(I[a].y - I[b].y);
//	int mid = (a + b) / 2;
//	int dl = ECP(a, mid);
//	int dr = ECP(mid + 1, b);
//	int d = m(dl, dr);
//	ele md = I[mid];
//	int dmin = d;
//
//	int k = 0;
//
//	for (int i = mid + 1; i <= b; i++){
//		if (I[i].x - md.x < sqrt(d)){
//			A.push_back(I[i]);
//		}
//		else
//			break;
//	}
//	for (int i = mid - 1; i >= a; i--){
//		if (md.x - I[i].x < sqrt(d)){
//			A.push_back(I[i]);
//		}
//		else
//			break;
//	}
//
//	int n = A.size();
//
//	for (int i = 0; i < n; i++){
//		for (int j = i + 1; j < n; j++){
//			int b = (A[i].x - A[j].x)*(A[i].x - A[j].x) + (A[i].y - A[j].y)*(A[i].y - A[j].y);
//			if (b < dmin)dmin = b;
//		}
//	}
//
//	A.clear();
//
//	return dmin;
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++){
//		int a, b;
//		scanf("%d %d", &I[i].x, &I[i].y);
//	}
//
//	sort(I + 1, I + 1 + n);
//
//	if (n > 1)printf("%d\n", ECP(1, n));
//	else
//		printf("0\n");
//}

#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <algorithm>

using namespace std;

class ele{
public:
	int x, y;
	bool operator<(const ele &A)const{
		if (x == A.x)return y < A.y;
		return x < A.x;
	}
}I[100003];

int m(int a, int b){ return a < b ? a : b; }

int ECP(int a, int b){
	if (a == b)return INT_MAX;
	if (a + 1 == b)return (I[a].x - I[b].x)*(I[a].x - I[b].x) + (I[a].y - I[b].y)*(I[a].y - I[b].y);
	int mid = (a + b) / 2;
	int dl = ECP(a, mid);
	int dr = ECP(mid + 1, b);
	int d = m(dl, dr);
	ele md = I[mid];
	int dmin = d;

	int l = mid + 1, r = b, m1, m2;
	while (l <= r){
		m2 = (l + r) / 2;
		if (I[m2].x - md.x < sqrt(d))l = m2 + 1;
		else
			r = m2 - 1;
	}

	l = a, r = mid - 1;
	while (l <= r){
		m1 = (l + r) / 2;
		if (md.x - I[m1].x >= sqrt(d))l = m1 + 1;
		else
			r = m1 - 1;
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

	for (int i = m1; i < m2; i++){
		for (int j = i+1; j <= m2; j++){
			int k = (I[i].x - I[j].x)*(I[i].x - I[j].x) + (I[i].y - I[j].y)*(I[i].y - I[j].y);
			dmin = m(dmin, k);
		}
	}

	return dmin;
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		int a, b;
		scanf("%d %d", &I[i].x, &I[i].y);
	}

	sort(I + 1, I + 1 + n);

	if (n > 1)printf("%d\n", ECP(1, n));
	else
		printf("0\n");
}