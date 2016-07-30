#include <stdio.h>
#include <algorithm>

using namespace std;

int a[4];

int main() {

	for (int i = 0; i < 3; i++)scanf("%d", &a[i]);

	sort(a, a + 3);

	int d = 203;

	for (int i = 0; i < 2; i++) {
		int k = a[i + 1] - a[i];
		if (d > k)d = k;
	}

	for (int i = 1; i < 3; i++) {

		if(a[i] == a[i-1] + d){

		}
		else {
			printf("%d\n", a[i - 1] + d);
			return 0;
		}
	}

	printf("%d\n", a[2] + d);

}