#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str[53];
char sstr[][5] = { "l", "o", "lo", "ll", "ol", "lol", "l*l" };
int ss[] = { 1, 1, 2, 2, 2, 3, 3 };

int main(){

	int t;
	scanf("%d", &t);

	while (t--){

		scanf("%s", str);

		int s = strlen(str);
		int ans = 0;
		for (int i = 0; i < s; i++){
			for (int j = 0; j <= 6; j++){
				if (i + ss[j] - 1 < s){
					int c = 0;
					for (int k = 0; k < ss[j]; k++){
						if (sstr[j][k] == '*' || str[i + k] == sstr[j][k]){
							c++;
						}
					}
					if (c == ss[j]){
						if (j == 6)c--;
						ans = max(ans, c);
					}
				}
			}
		}

		printf("%d\n", 3 - ans);

	}

}