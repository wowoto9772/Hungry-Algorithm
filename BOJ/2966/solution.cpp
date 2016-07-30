#include <stdio.h>
#include <algorithm>

using namespace std;

char str[103];
char ad[] = "ABC";
char br[] = "BABC";
char go[] = "CCAABB";

int main(){
	int n;
	scanf("%d", &n);
	scanf("%s", str);

	int ans = 0;
	int Ad = 0, Br = 0, Go = 0;
	int a = 0, b = 0, g = 0;

	for (int i = 0; i < n; i++){
		if (str[i] == ad[a])Ad++;
		a++;
		if (a == 3)a = 0;
		if (str[i] == br[b])Br++;
		b++;
		if (b == 4)b = 0;
		if (str[i] == go[g])Go++;
		g++;
		if (g == 6)g = 0;
	}

	ans = max(Ad, max(Br, Go));

	printf("%d\n", ans);

	if (Ad == ans)printf("Adrian\n");
	if (Br == ans)printf("Bruno\n");
	if (Go == ans)printf("Goran\n");
}