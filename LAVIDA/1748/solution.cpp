#include <stdio.h>

#include <string.h>

#include <memory.h>

char ret[222] = { 0 };

int Tim(char a[], char b[]){
	int ret2[222] = { 0 };

	int a_ = strlen(a), b_ = strlen(b);

	for (int i = 0; i < a_; i++)a[i] -= '0';
	for (int i = 0; i < b_; i++)b[i] -= '0';

	int t = 220, rt;
	rt = 220;

	for (int i = a_ - 1; i >= 0; i--){
		int t2 = 0;
		for (int j = b_ - 1; j >= 0; j--){
			ret2[t-t2] += a[i] * b[j];
			t2++;
		}
		t--;
	}

	for (int i = 220; i >= 1; i--){
		if (ret2[i] >= 10){
			ret2[i - 1] += ret2[i] / 10;
			ret2[i] %= 10;
		}
	}

	for (int i = 0; i <= 220; i++){
		if (ret2[i]){
			for (int j = i; j <= 220; j++){
				ret[j] = '0' + ret2[j];
			}
			return i;
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		char str[105] = { 0 }, str2[105] = { 0 };
		scanf("%s %s", str, str2);

		memset(ret, 0, sizeof(ret));

		printf("%s\n", ret + Tim(str, str2));
	}
}