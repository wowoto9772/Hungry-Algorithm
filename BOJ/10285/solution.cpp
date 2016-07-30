/*
1) SN�� �ƹ� ���� ����Ͽ� ���¸� �ٲ� �� �ִ�.
2) Si + 1 = 1�̸� Si + 2, Si + 3, ..., SN - 1, SN�� ��� 0�� ��, 
Si�� ����Ͽ� ���¸� �ٲ� �� �ִ�.�� ��Ģ�� ����ġ Si + 2, Si + 3, ..., SN - 1, SN�� ���� ���� ����ȴ�.���� ���, SN - 1�� SN�� 1�̱⸸ �ϸ� ����� �� �ִ�.
3) �� ���� �ϳ��� ����ġ�� ����� �� �ִ�
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