#include <stdio.h>

int sum(int v){
	int cmp[33] = { 0 };
	for (int i = 1; ; i++){
		cmp[i-1] = v / (1<<i) * (1<<(i-1));
		int rem = v % (1 << i);
		if (rem >= (1<<(i-1))){
			cmp[i - 1] += rem - (1 << (i - 1)) + 1;
		}
		cmp[i - 1] %= 2;
		if ((1 << i) > v)break;
	}

	int ans = 0;
	for (int i = 0; i < 32; i++){
		if (cmp[i])ans += (1 << i);
	}

	return ans;
}

int main(){

	int t;
	scanf("%d", &t);
	
	while (t--){

		int s, f;
		scanf("%d %d", &s, &f);

		printf("%d\n", sum(f) ^ sum(s - 1)); // xor s to f

	}

}