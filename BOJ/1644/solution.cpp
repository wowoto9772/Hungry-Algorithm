#include <stdio.h>

#define ll long long

ll S[300003];
bool p[4000003];

int main(){
	int n;
	scanf("%d", &n);

	int top = 1;

	for (ll i = 2; i <= n; i++){
		if (!p[i]){
			S[top] = S[top - 1] + i;
			top++;
			if (i*i <= n){
				for (int j = i*i; j <= n; j += i)p[j] = true;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i < top; i++){
		int l = i, r = top - 1, m;
		while (l <= r){
			m = (l + r) / 2;
			ll cmp = S[m] - S[i - 1];
			if (cmp == n){
				ans++;
				break;
			}
			else if (cmp < n)l = m + 1;
			else{
				r = m - 1;
			}
		}
	}

	printf("%d\n", ans);
}