#include <stdio.h>

#include <string.h>

int c['Z'+3];

char tar[23], str[23], out[23];

int main(){

	scanf("%s", tar);

	int t = strlen(tar);

	for(int i=0; i<t; i++)c[tar[i]]++;

	int n;
	scanf("%d", &n);

	int maxi = -1;

	for(int i=0; i<n; i++){

		scanf("%s", str);

		int s = strlen(str);

		int d['Z'+3] = {0};
		
		for(int j=0; j<s; j++)d[str[j]]++;

		d['L'] += c['L'];
		d['O'] += c['O'];
		d['V'] += c['V'];
		d['E'] += c['E'];

		int e[] = {d['L'], d['O'], d['V'], d['E']};

		int cmp = (e[0]+e[1]) * (e[0]+e[2]) * (e[0]+e[3]) * (e[1]+e[2]) * (e[1]+e[3]) * (e[2]+e[3]);
		cmp %= 100;

		if(maxi < cmp){
			maxi = cmp;
			strcpy(out, str);
		}else if(maxi == cmp){
			if(strcmp(str, out) < 0)strcpy(out, str);
		}

	}

	printf("%s\n", out);

}
