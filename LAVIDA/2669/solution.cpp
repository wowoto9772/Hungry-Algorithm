#include <stdio.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

bool isPrime(int c){
	for (int i = 2; i*i <= c; i++){
		if (!(c%i))return false;
	}return true;
}

int main(){
	int n;
	scanf("%d", &n);

	// case 1
	if (isPrime(n))printf("1\n%d\n", n);
	else{
		// case 2
		if (isPrime(n - 2)){
			printf("2\n2 %d\n", n - 2);
		}
		else{
			// case 3
			if (isPrime(n - 4)){
				printf("3\n2 2 %d\n", n - 4);
			}
			else{ // three odd numbers
				printf("3\n");
				for (int i = 3;; i += 2){
					if (isPrime(i) && isPrime(n - 3 - i)){
						printf("3 %d %d\n", min(i, n - 3 - i), max(i, n - 3 - i));
						break;
					}
				}
			}
		}
	}
}

// goldbach's weak congecture
/*
Every odd number greater than 5 can be expressed
as the sum of three primes
*/