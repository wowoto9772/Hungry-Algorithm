#include <stdio.h>
#include <string.h>

char str[88];

int main(){
	while (!strcmp(str, ""))gets(str);

	int s = strlen(str);

	bool chk['Z' + 3] = { 0 };
	bool space = false;
	bool first = false;

	for (int i = 0; i < s; i++){
		if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')continue;
		else{
			if (str[i] == ' '){
				space = true;
			}
			else{
				if (str[i] >= 'A'){
					if (chk[str[i]])continue;
					else{
						if (!first)space = false;
						if (space){
							printf(" ");
							space = false;
						}
						chk[str[i]] = true;
						printf("%c", str[i]);
						first = true;
					}
				}
				else{
					if (!first)space = false;
					if (space){
						// printf(" ");
						space = false;
					}
					// period, comma, question mark
					printf("%c", str[i]);
					first = true;
				}
			}
		}
	}
	printf("\n");
}