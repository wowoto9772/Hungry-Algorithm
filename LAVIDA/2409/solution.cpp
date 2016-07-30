#include <stdio.h>
#include <string.h>

char str[10003];

int T['z' - 'a' + 1];

int main()
{
	for (int i = 0; i < 26; i++)T[i] = 9;
	T['s' - 'a'] = 8;
	T['e' - 'a'] = 1;
	T['k' - 'a'] = 2;
	T['t' - 'a'] = 3;
	T['r' - 'a'] = 5;
	T['c' - 'a'] = 6;
	// secretkey

	scanf("%s", str);
	int s = strlen(str);

	int c = 0;

	for (int i = 8; i < s; ){
		if (str[i - 8] == 's' && str[i - 7] == 'e' && str[i - 6] == 'c' && str[i - 5] == 'r' && str[i - 4] == 'e' && str[i - 3] == 't' && str[i - 2] == 'k' && str[i - 1] == 'e' && str[i] == 'y'){
			c++;
			i+=9; // i++이나 i+=9나 상관이없음.
		}
		else{
			i += T[str[i] - 'a'];
		}
	}

	printf("%d\n", c);
}

//secretkey
//   5-321