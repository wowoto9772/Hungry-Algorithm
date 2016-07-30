#include <stdio.h>
#include <string.h>

#define ll long long

char str[23];
int s[300003];

ll cnt[23];

int main(){

	int n, k;
	scanf("%d %d", &n, &k);

	ll ans = 0;

	for (int i = 0; i < n; i++){
		scanf("%s", str);
		s[i] = strlen(str);

		cnt[s[i]]++;
		if (i - k - 1 >= 0){
			cnt[s[i - k - 1]]--;
		}
		ans += cnt[s[i]] - 1;

	}

	printf("%lld\n", ans);
}