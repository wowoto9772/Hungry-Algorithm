#include <stdio.h>
#include <string.h>

char str[1003];

int M(int a){
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')return 1;
	else
		return 0;
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%s", str);

		int s = strlen(str);

		int c = 0, m = 0;

		for (int i = 0; i < s / 2; i++){
			if (str[i] != str[s - 1 - i])c++;
			m += M(str[i]) + M(str[s - 1 - i]);
		}
		if (s % 2)m += M(str[s / 2]);
		
		if (!c)printf("Same %d\n", m);
		else
			printf("Not_Same %d\n", m);
	}
}