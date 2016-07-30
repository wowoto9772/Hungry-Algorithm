#include <stdio.h>
#include <string.h>

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		char str[103] = { 0 };

		while (!strcmp(str, ""))gets(str);

		int s = strlen(str);

		bool chk['z' + 3] = { 0 };

		for (int i = 0; i < s; i++){
			chk[str[i]] = true;
		}

		bool missing = false;
		bool ispangram = true;
		for (int i = 'a'; i <= 'z'; i++){
			if (chk[i] || chk[i - ('a' - 'A')])continue;
			else{
				if (!missing){
					missing = true;
					printf("missing ");
				}
				printf("%c", i);
				ispangram = false;
			}
		}

		if (ispangram)printf("pangram");

		printf("\n");
	}
}