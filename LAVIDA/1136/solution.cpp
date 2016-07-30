#include <stdio.h>
#include <string.h>

int main()
{
	char str[105] = { 0 };

	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%s", str);

		int s = strlen(str);

		bool f = false;

		for (int i = 0; i < s; i++){
			if (str[i] == '.'){
				f = true;
				bool g = false;
				for (int j = i + 1; !g && j < s; j++){
					if (str[j] != '0')g = true;
				}
				if (!g)f = false;
			}
		}

		if (!f)printf("YES\n");
		else
			printf("NO\n");
	}
}