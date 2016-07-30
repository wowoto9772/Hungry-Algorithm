#include <stdio.h>

bool isPrime(int a){
	if (a == 2)return true;
	else if (a < 2 || !(a % 2))return false;
	else{
		for (int i = 3; i*i <= a; i += 2){
			if (!(a%i))return false;
		}
		return true;
	}
}

int main(){
	int n;
	while (scanf("%d", &n) == 1 && n){
		bool wrg = true;
		for (int i = 2; i <= n / 2; i++){
			if (isPrime(i) && isPrime(n - i)){
				wrg = false;
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}
		}
		if (wrg)printf("Goldbach's conjecture is wrong.\n");
	}
}