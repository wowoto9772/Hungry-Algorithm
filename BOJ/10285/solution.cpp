/*
1) SN은 아무 때나 토글하여 상태를 바꿀 수 있다.
2) Si + 1 = 1이며 Si + 2, Si + 3, ..., SN - 1, SN은 모두 0일 때, 
Si를 토글하여 상태를 바꿀 수 있다.이 규칙은 스위치 Si + 2, Si + 3, ..., SN - 1, SN가 없을 때도 적용된다.예를 들어, SN - 1은 SN이 1이기만 하면 토글할 수 있다.
3) 한 번에 하나의 스위치만 토글할 수 있다
*/

#include <stdio.h>
#include <string.h>

char str[33];
char ing[33];
int w[33] = { 1 };

int main(){
	for (int i = 1; i <= 30; i++)w[i] = 2 * w[i - 1];

	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%s", str);

		int s = strlen(str);
		for (int i = 0; i < s; i++)ing[i] = '0';

		int ans = 0;
		for (int i = 0; i < s; i++){
			if (ing[i] != str[i]){
				ans += w[(s - 1) - i];
				if (i < s - 1)ing[i + 1] = (ing[i + 1] - '0') ^ 1 + '0';
			}
		}

		printf("%d\n", ans);
	}
}