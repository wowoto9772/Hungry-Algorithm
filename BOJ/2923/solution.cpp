#include <stdio.h>

int A[103], B[103];

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		int a, b;
		scanf("%d %d", &a, &b);

		A[a]++;
		B[b]++;

		if (i == 1){
			printf("%d\n", a + b);
		}
		else{
			int ma[103] = { 0 }, mb[103] = { 0 };
			for (int i = 1; i <= 100; i++)ma[i] = A[i], mb[i] = B[i];			
			int max = 0;

			int l = 1, r = 100;
			while (true){
				while (l <= 100 && !ma[l])l++;
				if (l == 101)break;
				while (r >= 1 && !mb[r])r--;
				if (r == 0)break;

				if (max < l + r){
					max = l + r;
				}
				int m = ma[l] < mb[r] ? ma[l] : mb[r];
				ma[l] -= m;
				mb[r] -= m;
			}
			
			for (int i = 1; i <= 100; i++)ma[i] = A[i], mb[i] = B[i];
			int max2 = 0;

			l = 1, r = 100;
			while (true){
				while (l <= 100 && !mb[l])l++;
				if (l == 101)break;
				while (r >= 1 && !ma[r])r--;
				if (r == 0)break;

				if (max2 < l + r){
					max2 = l + r;
				}
				int m = mb[l] < ma[r] ? mb[l] : ma[r];
				mb[l] -= m;
				ma[r] -= m;
			}

			if (max > max2)max = max2;

			printf("%d\n", max);
		}
	}
}