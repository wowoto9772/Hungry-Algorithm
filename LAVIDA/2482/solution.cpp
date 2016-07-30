#include <stdio.h>

bool chk[50000000];
int top = 1;
int A[1000003];

int main(){
	for (int i = 1; i <= 9; i++)chk[i] = true;

	for (int i = 1; i<=30000000 && top <= 1000000; i++){
		if (!chk[i])continue;
		A[top++] = i;
		if (i * 10 > 30000000)continue;
		bool rep[10] = { 0 };
		int s = i;
		while (s){
			rep[s % 10] = true;
			s /= 10;
		}
		for (int j = 0; j <= 9; j++){
			if (rep[j])continue;
			chk[i * 10 + j] = true;
		}
	}

	int n;
	while (scanf("%d", &n) == 1 && n){
		printf("%d\n", A[n]);
	}
}

// 9 * 9 * 8 * 7 * 6 * 5 * 4 * 3