#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		char s[3] = {0};
		scanf("%s", s);

		int k = strlen(s), a = 0;
		if(k == 2)a = (s[0] - '0') * 16;
		if(s[k-1] >= 'A' && s[k-1] <= 'Z')a += (s[k-1] - 'A' + 10);
		else if(s[k-1] >= 'a' && s[k-1] <= 'z')a += (s[k-1] - 'a' + 10);
		else
			a += s[k-1] - '0';

		bool f = false;
		for(int j='a'; !f && j<='z'; j++){
			for(int l='0'; !f && l<='9'; l++){
				int x = j ^ l;
				if(x == a){
					printf("-");
					f = true;
				}
			}
		}
		if(!f){
			printf(".");
		}
	}

	printf("\n");
}
