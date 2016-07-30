#include <stdio.h>
#include <algorithm>

using namespace std;

int a[505];

int main(){

	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	if (m + k - 1 <= n && n <= m * k){

		int top = 0;

		for (int i = k; i >= 1; i--)a[top++] = i;

		m--;

		int rem = n - top;

		int x = k;

		for (int i = 1; i <= m; i++){

			int got = 0;

			for (int j = k; j >= 1; j--){
				if (rem - j >= m - i){
					rem -= j;

					x += j;

					for (int y = x; y > x-j; y--)a[top++] = y;

					break;
				}
			}

		}

		for (int j = 0; j < top; j++)printf("%d ", a[j]);
	}
	else{
		printf("-1\n");
	}

}