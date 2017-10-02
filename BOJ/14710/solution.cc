#include <cstdio>

using namespace std;

int main(){

	int h, m;
	scanf("%d %d", &h, &m);

	h %= 30;
	if (12*h == m)printf("O");
	else
		printf("X");
}