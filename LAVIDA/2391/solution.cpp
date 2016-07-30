#include <stdio.h>
#include <string.h>

using namespace std;

char str[200005];
int P[100005];

void swp(char *a, char *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	freopen("large_dat10.in", "r", stdin);
	freopen("large_dat10.out", "w", stdout);

	scanf("%s", str);
	int n;
	scanf("%d", &n);

	int L = strlen(str);

	for (int i = 1; i <= n; i++){
		int a;
		scanf("%d", &a);
		P[a]++;
	}

	int f = 0;
	for (int i = 1; i <= L / 2; i++){
		f += P[i];
		if (f % 2)swp(&str[i - 1], &str[L - i]);
	}printf("%s\n", str);
}