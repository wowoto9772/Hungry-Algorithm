#include <stdio.h>

char str[55][55];
bool XR[53], XC[53];

int main()
{
	int R, C;
	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++){
		scanf("%s", str[i]);
		for (int j = 0; j < C; j++){
			if (str[i][j] == 'X'){
				XR[i] = true, XC[j] = true;
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			if (!XR[i] && !XC[j]){
				ans++;
				XR[i] = XC[j] = true;
			}
		}
	}
	for (int i = 0; i < R; i++)if (!XR[i])ans++;
	for (int i = 0; i < C; i++)if (!XC[i])ans++;

	printf("%d\n", ans);
}
/*

4 4
....
X...
...X
.X..

4 4
XXX.
XX..
X...
X...
*/