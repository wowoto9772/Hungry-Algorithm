#include <stdio.h>
#include <string.h>

char cmd[8], url[109][70];

int main()
{
	int i, j, c = 0;
	
	strcpy(url[0], "http://www.acm.org/");

	while (1) {

		scanf("%s", cmd);

		if (!strcmp(cmd, "VISIT")) {
			scanf("%s", url[++c]);
			printf("%s\n", url[c]);
			strcpy(url[c + 1], "");
		}
		else if (!strcmp(cmd, "BACK")) {
			if (!c) {
				printf("Ignored\n");
			}
			else {
				c--;
				printf("%s\n", url[c]);
			}
		}
		else if (!strcmp(cmd, "FORWARD")) {
			if (!strcmp(url[c+1], "")) {
				printf("Ignored\n");
			}
			else {
				++c;
				printf("%s\n", url[c]);
			}
		}
		else if (!strcmp(cmd, "QUIT")) {
			break;
		}
	}
	return 0;
}
