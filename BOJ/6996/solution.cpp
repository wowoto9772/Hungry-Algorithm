#include <stdio.h>
#include <string.h>

int anagram(char *a, char *b) {

	int s = strlen(a);
	int c['z' + 3] = { 0 };

	for (int i = 0; i < s; i++)c[a[i]]++;

	s = strlen(b);
	for (int i = 0; i < s; i++)c[b[i]]--;

	for (int i = 'a'; i <= 'z'; i++)if (c[i])return 0;
	return 1;

}

char a[103], b[103];

char out[][15] = { "NOT anagrams.", "anagrams." };

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%s %s", a, b);

		printf("%s & %s are %s\n", a, b, out[anagram(a, b)]);

	}

}