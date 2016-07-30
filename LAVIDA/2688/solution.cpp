#include <stdio.h>
#include <string.h>

char str[10003];
int sq[103];
int pars[10003];

int main(){
	int top = 1;
	for (int i = 1; i <= 100; i++)sq[i] = i*i;
	for (int i = 0; i <= 10000; i++){
		if (i <= sq[top])pars[i] = top;
		else{
			pars[i] = ++top;
		}
	}

	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%s", str);

		int L = strlen(str);
		int M = pars[L];

		int top = 0;
		int map[103][103] = { 0 };
		for (int i = 1; i <= M && top < L; i++){
			for (int j = 1; j <= M && top < L; j++){
				map[i][j] = str[top++];
			}
		}

		for (int j = 1; j <= M; j++){ // rotate clockwise
			for (int i = M; i >= 1; i--){
				if (map[i][j])printf("%c", map[i][j]);
			}
		}

		printf("\n");
	}
}