#include <cstdio>

using namespace std;

int main(){

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	c <<= 1;

	a += b;
	if (a >= c)a -= c;
	printf("%d\n", a);

}