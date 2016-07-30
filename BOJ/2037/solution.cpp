#include <stdio.h>
#include <string.h>

char str[4003];

int ty['Z' + 3];

char *org = "0ADGJMPTW";

int main() {
	
	ty['A'] = ty['B'] = ty['C'] = 1;
	ty['D'] = ty['E'] = ty['F'] = 2;
	ty['G'] = ty['H'] = ty['I'] = 3;
	ty['J'] = ty['K'] = ty['L'] = 4;
	ty['M'] = ty['N'] = ty['O'] = 5;
	ty['P'] = ty['Q'] = ty['R'] = ty['S'] = 6;
	ty['T'] = ty['U'] = ty['V'] = 7;
	ty['W'] = ty['X'] = ty['Y'] = ty['Z'] = 8;

	int p, w;
	scanf("%d %d", &p, &w);

	fgets(str, 4000, stdin); // for buffer
	fgets(str, 4000, stdin); 

	int s = strlen(str);
	if(str[s - 1] == '\n') s--; // for '\n'

	int ans = 0;
	for (int i = 0; i < s; i++) {

		if (str[i] == ' ')ans += p;
		else {
			ans += p * (str[i] - org[ty[str[i]]] + 1);
		}

		if (i) {
			if (ty[str[i]] == ty[str[i - 1]] && str[i] != ' ')ans += w;
		}
	}

	printf("%d\n", ans);


}