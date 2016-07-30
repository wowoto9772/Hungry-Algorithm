#include <stdio.h>
#include <string.h>

char r[8];

int pen['Z' + 3];
bool ac['Z' + 3];

int main(){

	int solv = 0, penl = 0;

	int t;
	while (scanf("%d", &t) == 1 && t != -1){

		char p;
		scanf(" %c %s", &p, &r);

		if (!ac[p]){
			if (!strcmp(r, "wrong"))pen[p]++;
			else if (!strcmp(r, "right")){
				ac[p] = true;
				penl += pen[p] * 20 + t;
				solv++;
			}
		}
	
	}

	printf("%d %d\n", solv, penl);


}