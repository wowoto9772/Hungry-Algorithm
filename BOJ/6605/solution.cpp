#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;
long long humble[10000];
long long power(int num, int jegob) {
	long long ans = 1;
	for (long long i = 0; i<jegob; i++) {
		ans *= num;
	}
	return ans;
}
int main()
{
	int num = 1;
	for (long long i = 0; i <= 31; i++) {
		int i_num = num;
		for (long long j = 0; j <= 31; j++) {
			int j_num = num;
			for (long long k = 0; k <= 31; k++) {
				int k_num = num;
				for (long long l = 0; l <= 31; l++) {
					long long temp = 1;
					temp *= power(2, i);
					if (temp > 2000000000)break;
					temp *= power(3, j);
					if (temp > 2000000000)break;
					temp *= power(5, k);
					if (temp > 2000000000)break;
					temp *= power(7, l);
					if (temp > 2000000000)break;
					humble[num] = temp;
					num++;
				}
				if (k_num == num)break;
			}
			if (j_num == num)break;
		}
		if (i_num == num)break;
	}
	
	sort(humble + 1, humble + num);

	int n;
	while (scanf("%d", &n) == 1 && n) {
		printf("The ");
		if (n % 10 == 1) {
			if (n % 100 > 10 && n % 100 < 20)printf("%dth ", n);
			else
				printf("%dst ", n);
		}
		else if (n % 10 == 2) {
			if (n % 100 > 10 && n % 100 < 20)printf("%dth ", n);
			else
				printf("%dnd ", n);
		}
		else if (n % 10 == 3) {
			if (n % 100 > 10 && n % 100 < 20)printf("%dth ", n);
			else
				printf("%drd ", n);
		}
		else
			printf("%dth ", n);

		printf("humble number is %lld.\n", humble[n]);

	}
}