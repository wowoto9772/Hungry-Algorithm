#include <stdio.h>

int gcd(int a, int b) {
	int m = 1;
	while (m) {
		m = a % b;
		a = b;
		b = m;
	}return a;
}

int main() {

	int a, b;
	
	int c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	int s = a*d+b*c, m = b*d;

	int g = gcd(s, m);
	
	s /= g, m /= g;

	printf("%d %d\n", s, m);


}