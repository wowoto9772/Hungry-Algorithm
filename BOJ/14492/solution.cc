#include <cstdio>

using namespace std;

int a[303][303], b[303][303], c[303][303];

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)scanf("%d", &b[i][j]);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			for (int k = 1; k <= n; k++){
				c[i][j] |= a[i][k] & b[k][j];
			}
		}
	}

	int d = 0;
	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)d += c[i][j];

	printf("%d\n", d);

}