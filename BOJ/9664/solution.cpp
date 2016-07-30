#include <stdio.h>

int main(){
	int n, rem;
	scanf("%d %d", &n, &rem);

	int di = rem / (n - 1);

	int Max = di + rem;

	int Min;

	if (rem % (n - 1)){
		Min = Max;
	}
	else
		Min = Max - 1;

	printf("%d %d\n", Min, Max);
}