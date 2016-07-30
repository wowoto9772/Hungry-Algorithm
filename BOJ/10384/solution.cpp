#include <stdio.h>
#include <string.h>
#include <limits.h>

#include <algorithm>

using namespace std;

char str[1003];

int main(){

	int n;
	scanf("%d", &n);

	gets(str);
	for (int i = 1; i <= n; i++){

		gets(str); // includes empty string

		int s = strlen(str);
		int c['z' + 3] = { 0 };

		for (int j = 0; j < s; j++){

			if (str[j] <= 'Z' && str[j] >= 'A')c[str[j] + 'a' - 'A']++;
			else
				c[str[j]]++;

		}

		int f = INT_MAX;
		for (int j = 'a'; j <= 'z'; j++){

			f = min(f, c[j]);

		}

		printf("Case %d: ", i);

		if (!f)printf("Not a pangram\n");
		else if (f == 1)printf("Pangram!\n");
		else if (f == 2)printf("Double pangram!!\n");
		else{
			printf("Triple pangram!!!\n");
		}

	}

}