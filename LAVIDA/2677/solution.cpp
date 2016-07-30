#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <string>

using namespace std;

char str[5003][103];
int c[5003][103][26];
int frt[5003][26];
int lst[5003][26];
char qur[5];

int main(){

	memset(frt, 0xff, sizeof(frt));
	memset(lst, 0xff, sizeof(lst));

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++){
		scanf("%s", str[i]);
		int s = strlen(str[i]);
		for (int j = 0; j < s; j++){
			for (int k = 0; k < 26; k++){
				if (k == str[i][j] - 'a'){
					if (j){
						c[i][j][k] = c[i][j - 1][k] + 1;
					}
					else{
						c[i][j][k] = 1;
					}
				}
				else{
					c[i][j][k] = c[i][j - 1][k];
				}
			}
			if (frt[i][str[i][j] - 'a'] == -1){
				frt[i][str[i][j] - 'a'] = j;
			}

			lst[i][str[i][j] - 'a'] = j;
		}
	}

	for (int i = 1; i <= m; i++){
		scanf("%s", qur);
		int first = qur[0] + 'z' - 'Z';
		int middle = qur[1] + 'z' - 'Z';
		int last = qur[2] + 'z' - 'Z';

		bool ans = false;
		for (int j = 1; j <= n; j++){
			if (frt[j][first - 'a'] == -1)continue;
			else if (lst[j][last - 'a'] == -1)continue;
			else{
				if (frt[j][first - 'a'] >= lst[j][last - 'a'])continue;
				int s = frt[j][first - 'a'];
				int e = lst[j][last - 'a'];
				int flag = c[j][e - 1][middle - 'a'] - c[j][s][middle - 'a'];
				if (flag){
					printf("%s\n", str[j]);
					ans = true;
					break;
				}
			}
		}

		if (!ans)printf("No valid word\n");
	}
}