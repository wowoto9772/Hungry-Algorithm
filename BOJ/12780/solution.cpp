#include <stdio.h>
#include <string.h>

char org[100003], tar[13];

int main() {

	scanf("%s %s", org, tar);

	int s = strlen(org);
	int k = strlen(tar);

	int key = 0;
	int rem = 1;

	for (int i = 0; i < k; i++) {

		rem *= 26;
		key = key * 26 + tar[i] - 'A';

	}

	int ans = 0;
	int cmp = 0;
	for (int i = 0; i < s; i++) {

		cmp = cmp * 26 + org[i] - 'A';
		
		if (i >= k)cmp -= (org[i - k] - 'A') * rem;

		if (i >= k - 1) {
			if (cmp == key)ans++;
		}
	}

	printf("%d\n", ans);

} // karp-rabin