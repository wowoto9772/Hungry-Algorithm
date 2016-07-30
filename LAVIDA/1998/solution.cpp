#include <stdio.h>

#include <string.h>

#include <memory.h>

char ret[110] = { 0 };

int Minus(char a[], char b[]){
	int a_ = strlen(a), b_ = strlen(b);

	for (int i = 0; i < a_; i++)a[i] -= '0';
	for (int i = 0; i < b_; i++)b[i] -= '0';

	int rt = 108;

	int t = a_ - 1, t2 = b_ - 1;
	for (;; t--, t2--){
		if (t < 0 && t2 < 0)break;
		if (t >= 0)ret[rt] += a[t];
		if (t2 >= 0)ret[rt] -= b[t2];
		rt--;
	}

	for (int i = 108; i >= 1; i--){
		if (ret[i] < 0){
			ret[i - 1]--;
			ret[i] += 10;
		}
	}

	if (ret[0] == -1){ // 정답이 -값
		char ret2[110] = { 0 };
		printf("-");
		ret2[0] = 1;

		for (int i = 108; i >= 1; i--){
			ret2[i] -= ret[i];
			if (ret2[i] < 0){
				ret2[i - 1]--;
				ret2[i] += 10;
			}
		}

		for (int i = 0; i <= 108; i++){
			if (ret2[i]){
				for (int j = i; j <= 108; j++){
					ret[j] = ret2[j] += '0';
				}
				return i;
			}
		}
	}
	else{
		for (int i = 0; i <= 108; i++){
			if (ret[i]){
				for (int j = i; j <= 108; j++)ret[j] += '0';
				return i;
			}
		}
	}

	printf("0");
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		char str[105] = { 0 }, str2[105] = { 0 };
		scanf("%s %s", str, str2);

		memset(ret, 0, sizeof(ret));

		printf("%s\n", ret + Minus(str, str2));
	}
}