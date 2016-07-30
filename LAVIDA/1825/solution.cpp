#include <stdio.h>
#include <string.h>
#include <memory.h>

char ret[55];
int ret2[56];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int a;
		scanf("%s %d", ret, &a);

		int s = strlen(ret);
		s++;

		memset(ret2, 0, sizeof(ret2));

		for (int i = 2; i <= s; i++)ret2[i] = ret[i - 2] - '0';

		for (int i = 0; i < 10; i++){
			bool f = false;
			for (int j = 0; !f && j <= s; j++){
				if (ret2[j]){
					for (int k = j; !f && k <= s; k++){
						if (ret2[k] == a)f = true;
					}
				}
				else if (j == s){ // 0 0 들어왔을때를 대비해서....
					if (ret2[j] == a)f = true;
				}
			}
			if (f){
				printf("%d\n", i);
				break;
			}
			else{
				ret2[s]++;
				for (int j = s; j >= 1; j--){
					if (ret2[j] >= 10){
						ret2[j - 1] += ret2[j] / 10;
						ret2[j] %= 10;
					}
				}
			}
		}
	}
}