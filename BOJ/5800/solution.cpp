#include <stdio.h>
#include <algorithm>

using namespace std;

int a[52];

int main(){
	int t;
	scanf("%d", &t);

	for (int tc = 1; tc <= t; tc++){
		int n;
		scanf("%d", &n);

		int Max = 0, Min = 103, Gap = -1;

		for (int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		for (int i = 0; i < n; i++){
			if (Max < a[i])Max = a[i];
			if (Min > a[i])Min = a[i];
			if (i && a[i] - a[i - 1] > Gap)Gap = a[i] - a[i - 1];
		}

		printf("Class %d\nMax %d, Min %d, Largest gap %d\n", tc, Max, Min, Gap);
	}
}