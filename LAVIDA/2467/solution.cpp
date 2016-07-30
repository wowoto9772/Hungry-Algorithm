#include <stdio.h>

int f[10] = { 1 };
bool chk[1000003];

int main(){
	for (int i = 1; i <= 9; i++)f[i] = f[i - 1] * i;
	for (int i = 1; i < 1024; i++){
		int c = 0;
		for (int j = 0; j < 10; j++){
			if (i&(1 << j)){
				c += f[j];
			}
		}
		if (c <= 1000000)chk[c] = true;
	}

	int n;
	while (scanf("%d", &n) == 1 && n >= 0){
		printf("%s\n", chk[n] ? "YES" : "NO");
	}

}