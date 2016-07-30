#include <stdio.h>

int A[10];
int B[10];

int main(){
	for (int i = 0; i < 10; i++)scanf("%d", &A[i]);
	for (int i = 0; i < 10; i++)scanf("%d", &B[i]);

	int a = 0, b = 0;
	int last = -1;
	for (int i = 0; i < 10; i++){
		if (A[i] > B[i]){
			a += 3;
			last = 0;
		}
		else if (A[i] < B[i]){
			b += 3;
			last = 1;
		}
		else
			a++, b++;
	}

	printf("%d %d\n", a, b);
	if (a == b){
		if (last == -1)printf("D\n");
		else if (last)printf("B\n");
		else
			printf("A\n");
	}
	else if (a > b)printf("A\n");
	else
		printf("B\n");
}