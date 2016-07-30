#include <stdio.h>

bool chk[2002][2002];

int gcd(int a, int b){
	int mod = 1;
	while (mod){
		mod = a % b;
		a = b;
		b = mod;
	}return a;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	int ans = 0;

	for (int i = n; i <= m; i++){
		for (int j = 1; j <= i; j++){
			int g = gcd(i, j);
			int i_ = i / g;
			int j_ = j / g;
			if (chk[i_][j_])continue;
			else{
				chk[i_][j_] = true;
				ans++;
			}
		}
	}

	printf("%d\n", ans);
}