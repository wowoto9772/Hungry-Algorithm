#include <stdio.h>
#include <algorithm>

using namespace std;

int a[1003];
int b[1003];

int da[1003][1003];
int db[1003][1003];

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		da[i][i] = a[i];
	}
	for (int i = 0; i < n; i++){
		scanf("%d", &b[i]);
		db[i][i] = b[i];
	}

	for (int j = 1; j < n; j++){
		for (int i = 0; i+j < n; i++){
			da[i][i + j] = da[i][i + j - 1] ^ a[i + j];
			db[i][i + j] = db[i][i + j - 1] ^ b[i + j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			ans = max(ans, da[i][j] + db[i][j]);
		}
	}

	printf("%d\n", ans);

}