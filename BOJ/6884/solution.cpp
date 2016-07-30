#include <stdio.h>

int s[10003];
bool p[3000003] = { true, true };

bool isPrime(int a){
	if (a == 1)return false;
	else if (a == 2)return true;
	else{
		if (a % 2){
			for (int i = 3; i*i <= a; i += 2){
				if (!(a%i))return false;
			}
			return true;
		}
		else{
			return false;
		}
	}
}

int main(){
	for (int i = 2; i*i <= 3000000; i++){
		if (!p[i]){
			for (int j = i*i; j <= 3000000; j += i)p[j] = true;
		}
	}

	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		int ans = 10002, st;

		for (int i = 1; i <= n; i++){
			int a;
			scanf("%d", &a);
			s[i] = s[i - 1] + a;
		}

		for (int k = 1; k < n && ans == 10002; k++){
			for (int i = 1; i + k <= n && ans == 10002; i++){
				int cmp = s[i + k] - s[i - 1];
				if (cmp <= 3000000){
					if (!p[cmp]){
						ans = k + 1;
						st = i;
					}
				}
				else{
					if (isPrime(cmp)){
						ans = k + 1;
						st = i;
					}
				}
			}
		}

		if (ans == 10002)printf("This sequence is anti-primed.\n");
		else{
			printf("Shortest primed subsequence is length %d: ", ans);
			for (int i = st; i < st + ans; i++){
				printf("%d", s[i] - s[i-1]);
				if (i < st + ans - 1)printf(" ");
			}printf("\n");
		}
	}
}