#include <stdio.h>
#include <string.h>

char str[1000003];

int main(){

	int t;
	scanf("%d", &t);

	while(t--){

		int a, b;
		scanf("%d %d", &a, &b);

		int mp[26] = {0};

		for(int i=0; i<26; i++){
			mp[i] = (a * i + b) % 26 + 'A';
		}

		scanf("%s", str);

		int s = strlen(str);

		for(int i=0; i<s; i++){
			printf("%c", mp[str[i]-'A']);
		}

		printf("\n");

	}

}
