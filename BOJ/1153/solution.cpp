#include <stdio.h>
#include <algorithm>

using namespace std;

bool p[1000003] = { true, true, };

bool isPrime(int v) {
	return !p[v];
}

int a[6];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 2; i*i <= n; i++) {
		if (p[i])continue;
		for (int j = i*i; j <= n; j += i) {
			p[j] = true;
		}
	}

	bool flag = false;

	if (n < 8)flag = true;
	else {
		if (n % 2) {
			// odd
			// 2, 3
			if (n - 5 >= 4) {
				a[0] = 2, a[1] = 3;
				for (int j = 2; j <= (n - 5) / 2; j++) {
					if (isPrime(j) && isPrime(n - 5 - j)) {
						a[2] = j, a[3] = n - 5 - j;
						break;
					}
				}
			}else {
				flag = true;
			}
		}
		else {
			if (n - 4 >= 4) {
				a[0] = a[1] = 2;
				for (int j = 2; j <= (n - 4) / 2; j++) {
					if (isPrime(j) && isPrime(n - 4 - j)) {
						a[2] = j, a[3] = n - 4 - j;
						break;
					}
				}
			}else{
				flag = true;
			}
		}
	}

	if (flag)printf("-1\n");
	else {
		sort(a, a + 4);
		for (int i = 0; i < 4; i++)printf("%d ", a[i]);
	}

}
// Goldbach's conjecture
// Every even integer greater than 2 can be expressed as the sum of two primes.