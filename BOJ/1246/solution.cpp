//#include <stdio.h>
//
//int a[1003];
//
//int main(){
//
//	int n, p;
//	scanf("%d %d", &n, &p);
//
//	int m = 1000001, M = 0;
//	for (int i = 1; i <= p; i++){
//		scanf("%d", &a[i]);
//		if (m > a[i])m = a[i];
//		if (M < a[i])M = a[i];
//	}
//
//	int ans = 0, ans2 = 0;
//	for (int i = m; i <= M; i++){
//		int c = 0;
//		for (int j = 1; j <= p; j++){
//			if (a[j] >= i){
//				c++;
//				if (c == n)break;
//			}
//		}
//		if (ans < c*i)ans = c*i, ans2 = i;
//	}
//
//	printf("%d %d\n", ans2, ans);
//}

#include <stdio.h>
#include <algorithm>

using namespace std;

int a[1003];

int main(){

	int n, p;
	scanf("%d %d", &n, &p);

	int m = 1000001, M = 0;
	for (int i = 0; i < p; i++){
		scanf("%d", &a[i]);
		if (M < a[i])M = a[i];
		if (m > a[i])m = a[i];
	}

	sort(a, a + p);

	int ans = 0, ans2 = 0;
	for (int i = m; i <= M; i++){		
		
		int w = lower_bound(a, a + p, i) - a;
		
		w = p - w;

		if (w > n)w = n;

		if (ans < i*w)ans = i*w, ans2 = i;
	}

	printf("%d %d\n", ans2, ans);
}