#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {

	int a, b, c, d, p;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &p);

	int x = p * a, y = b;

	y += max(p - c, 0) * d;

	printf("%d\n", min(x, y));

}