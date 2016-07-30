#include <stdio.h>
#include <string.h>

char a[13], b[103];
int p[13];
char t[13][13];
int main(){
	while (scanf("%s", a) == 1){
		if (!strcmp(a, "THEEND"))break;
		int sa = strlen(a);

		int c['z' + 3] = { 0 };
		for (int i = 0; i < sa; i++){
			c[a[i]]++;
		}

		int g = 0;
		for (int i = 'A'; i <= 'Z'; i++){
			if (c[i]){
				for (int j = 0; c[i] && j < sa; j++){
					if (a[j] == i){
						p[++g] = j+1;
						c[i]--;
					}
				}
			}
		}

		scanf("%s", b);
		int sb = strlen(b);

		g = sb / sa + (sb%sa);

		int f = 0;
		for (int i = 1; i <= sa; i++){
			for (int j = 1; j <= g; j++){
				if (f < sb)t[j][p[i]] = b[f++];
				else
					t[j][p[i]] = 0;
			}
		}
		for (int i = 1; i <= g; i++){
			for (int j = 1; j <= sa; j++){
				if (t[i][j])printf("%c", t[i][j]);
			}
		}
		printf("\n");
	}
}