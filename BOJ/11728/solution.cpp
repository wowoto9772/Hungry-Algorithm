#include <stdio.h>

int A[1000003], B[1000003];

int main(){
	int a, b;
	scanf("%d %d", &a, &b);

	for (int i = 1; i <= a; i++)scanf("%d", &A[i]);
	for (int i = 1; i <= b; i++)scanf("%d", &B[i]);

	int l = 1, r = 1;
	while (true){
		if (l <= a && r <= b){
			if (A[l] > B[r]){
				printf("%d ", B[r++]);
			}
			else{
				printf("%d ", A[l++]);
			}
		}
		else{
			if (l > a){
				if (r > b)break;
				printf("%d ", B[r++]);
			}
			else{
				if (l > a)break;
				printf("%d ", A[l++]);
			}
		}
	}
}