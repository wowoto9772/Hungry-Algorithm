#include <stdio.h>
#include <string.h>

char str[2003];
bool p[2003] = { true, true };

int main(){
	for (int i = 2; i*i <= 2000; i++){
		if (!p[i]){
			for (int j = i + i; j <= 2000; j += i){
				p[j] = true;
			}
		}
	}

	int t;
	scanf("%d", &t);

	for (int T = 1; T <= t; T++){
		scanf("%s", str);
		int s = strlen(str);
		
		printf("Case %d: ", T);

		int c['z' + 3] = { 0 };

		for (int i = 0; i < s; i++){
			c[str[i]]++;
		}

		bool flag = false;
		for (int i = 1; i <= 'z'; i++){
			if (!p[c[i]]){
				printf("%c", i);
				flag = true;
			}
		}

		printf("%s\n", flag ? "" : "empty");
	}
}