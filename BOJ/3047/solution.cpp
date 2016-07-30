#include <stdio.h>

void swp(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

char s[5];

int main() {

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if (a > b)swp(a, b);
	if (a > c)swp(a, c);
	if (b > c)swp(b, c);

	int par['D' + 3];
	par['A'] = a;
	par['B'] = b;
	par['C'] = c;

	scanf("%s", s);

	for (int i = 0; i < 3; i++)printf("%d ", par[s[i]]);

}