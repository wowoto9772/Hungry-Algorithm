#include <cstdio>

using namespace std;

int gcd(int a, int b){
	int m = 1;
	while (m){
		m = a % b;
		a = b;
		b = m;
	}return a;
}

int main(){
	int a, b;
	scanf("%d:%d", &a, &b);

	int g = gcd(a, b);
	a /= g, b /= g;
	printf("%d:%d\n", a, b);
}