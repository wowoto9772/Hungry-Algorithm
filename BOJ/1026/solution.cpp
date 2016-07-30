#include <stdio.h>
#include <algorithm>

using namespace std;

int a[53], b[53];

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	sort(a, a + n);

	for (int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}

	sort(b, b + n);

	int j = n - 1;
	int ans = 0;
	for (int i = 0; i < n; i++){
		ans += a[i] * b[j];
		j--;
	}

	printf("%d\n", ans);
}