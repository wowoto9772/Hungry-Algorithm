#include <stdio.h>

void hanoi(int n, int m, int r){
	if (n == 1){
		printf("%d %d\n", m, r);
	}
	else{
		hanoi(n - 1, m, 6 - m - r);
		printf("%d %d\n", m, r);
		hanoi(n - 1, 6 - m - r, r);
	}
}

int main(){
	int n;
	scanf("%d", &n);

	printf("%d\n", (1 << n) - 1);
	hanoi(n, 1, 3); // hanoi(n, 1, 2) : 2번째 위치로 타워를 옮긴다.
}